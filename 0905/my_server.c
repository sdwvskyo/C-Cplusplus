#include "my_server.h"

void travelChilds(Child *childs, int childs_len, fd_set *set)
{
	int val;
	for (int i = 0; i < childs_len; i++) {
		if (FD_ISSET(childs[i].sfd, set)) {
			read(childs[i].sfd, &val, 4);
			childs[i].state = IDLE;
		}
	}
}

void assignTask(Child *childs, int childs_len, int sfd)
{
	for (int i = 0; i < childs_len; i++) {
		if (childs[i].state == IDLE) {
			send_fd(childs[i].sfd, sfd);
			childs[i].state = BUSY;
			break;
		}
	}
}

Child * initChilds(int len)
{
	Child *childs = (Child *)calloc(len, sizeof(Child));
	if (childs == NULL) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < len; i++) {
		int sfd_pair[2];
		pid_t pid;
		if (socketpair(AF_LOCAL, SOCK_STREAM, 0, sfd_pair) < 0) {
			perror("socketpair");
			exit(EXIT_FAILURE);
		}	
		pid = fork();
		if (pid < 0) {
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0) {
			close(sfd_pair[1]);
			work(sfd_pair[0]);
			exit(1);
		} else {
			childs[i].state = IDLE;
			childs[i].pid = pid;
			childs[i].sfd = sfd_pair[1];
			close(sfd_pair[0]);
		}
	}
	return childs;
}

static void toUpper(char *str)
{
	while (str) {
		if (*str >= 'a' && *str <= 'z') {
			*str -= 32;
		}
		str++;
		printf("to upper\n");
	}
}

void work(int sfd)
{
	int sfd_client;
	pid_t pid = getpid();
	while (1) {
		recv_fd(sfd, &sfd_client);
		handler(sfd_client);
		write(sfd, &pid, sizeof(pid));
	}
}

void handler(int sfd)
{
	Msg msg;
	int recvn;
	while (1) {
		memset(&msg, 0, sizeof(Msg));
		recvn = recvTcp(sfd, &msg, 4);
		if (recvn == 0)
			break;
		recvTcp(sfd, msg.buf, msg.len);
		sendTcp(sfd, &msg, msg.len + 4);
	}

}

void send_fd(int sfd, int fd_file)
{
	struct msghdr *msg = (struct msghdr *)calloc(1, sizeof(struct msghdr));
	struct cmsghdr *cmsg = (struct cmsghdr *)calloc(1, CMSG_LEN(sizeof(int)));
	if (msg == NULL || cmsg == NULL) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}
	char buf[32] = "hello world!\n";
	struct iovec bufs[1];
	bufs[0].iov_base = buf;
	bufs[0].iov_len = strlen(buf);

	cmsg->cmsg_len = CMSG_LEN(sizeof(int));
	cmsg->cmsg_level = SOL_SOCKET;
	cmsg->cmsg_type = SCM_RIGHTS;
	*(int *)CMSG_DATA(cmsg) = fd_file;

	msg->msg_name = NULL;
	msg->msg_namelen = 0;
	msg->msg_iov = bufs;
	msg->msg_iovlen = 1;
	msg->msg_control = cmsg;
	msg->msg_controllen = cmsg->cmsg_len;
	msg->msg_flags = 0;
	int sendn = sendmsg(sfd, msg, 0);
	if (sendn < 0) {
		perror("sednmsg");
		exit(EXIT_FAILURE);
	}
	printf("send len: %d\n", sendn);
}

void recv_fd(int sfd, int *fd_file)
{
	struct msghdr *msg = (struct msghdr *)calloc(1, sizeof(struct msghdr));
	struct cmsghdr *cmsg = (struct cmsghdr *)calloc(1, CMSG_LEN(sizeof(int)));
	if (msg == NULL || cmsg == NULL) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}
	char buf1[32] = "";
	struct iovec bufs[1];
	bufs[0].iov_base = buf1;
	bufs[0].iov_len = 31;

	msg->msg_name = NULL;
	msg->msg_namelen = 0;
	msg->msg_iov = bufs;
	msg->msg_iovlen = 1;
	msg->msg_flags = 0;
	msg->msg_control = cmsg;
	msg->msg_controllen = CMSG_LEN(sizeof(int));
	int recvn = recvmsg(sfd, msg, 0);
	if (recvn < 0) {
		perror("recvmsg");
		exit(EXIT_FAILURE);
	}
	*fd_file = *(int *)CMSG_DATA((struct cmsghdr *)msg->msg_control);
	printf("buf1: %s, recv len: %d\n", buf1, recvn);
}
