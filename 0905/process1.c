/*************************************************************************
	> File Name: server.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 五  9/ 5 16:26:45 2014
 ************************************************************************/

#include <my_socket.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/socket.h>

#include <sys/uio.h>

void handler(int arg)
{
	while (waitpid(-1, NULL, WNOHANG) > 0) ;
}

int main(int argc, char *argv[])
{
	signal(SIGCHLD, handler);
	int sfd_server = initTcpServer(argv[1], atoi(argv[2]));
	int sfd_client;
	while (sfd_client = accept(sfd_server, NULL, NULL)) {
		if (sfd_client == -1) {
			if (errno == EINTR) {
				continue;
			} else {
				break;
			}
		} else {
			if (fork() == 0) {

				close(sfd_client);
				exit(1);
			}
		}
		close(sfd_client);
	}
	return 0;
}

struct msghdr {
	void		*msg_name;	/* [XSI] optional address */
	socklen_t	msg_namelen;	/* [XSI] size of address */
	struct		iovec *msg_iov;	/* [XSI] scatter/gather array */
	int		msg_iovlen;	/* [XSI] # elements in msg_iov */
	void		*msg_control;	/* [XSI] ancillary data, see below */
	socklen_t	msg_controllen;	/* [XSI] ancillary data buffer len */
	int		msg_flags;	/* [XSI] flags on received message */
};

