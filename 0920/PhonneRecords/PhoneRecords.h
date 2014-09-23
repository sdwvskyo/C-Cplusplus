#ifndef PHONERECORDS_H
#define PHONERECORDS_H 

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Record{
	public:
		Record(const string phone = "", const string name = "", const string address = "")
			: phone_(phone), name_(name), address_(address)
			{  }
		~Record() { }
		void setPhoneNo(const string &phone) { phone_ = phone; }
		void setName(const string &name) { name_ = name; }
		void setAddress(const string &address) { address_ = address; }
		void setAll(const string &phone, const string &name, const string &address);
		string getPhone() const { return phone_; }
		string getName() const {return name_; }
		string getAddress() const { return address_; }
		void printRecord() const;
	private:
		string phone_;
		string name_;
		string address_;
};

class PhoneRecords{
	public:
		PhoneRecords() {  }
		~PhoneRecords() {  }
		
		void addRecord(const Record &record);
		void addRecord(const string &phone, const string &name, const string &address);
		Record deleteRecord(const string &phone);
		vector<Record> findByName(const string &name) const;
		vector<Record> findByAddress(const string &address) const;
		Record findByPhoneNo(const string &phone) const;
		void printRecords() const;
	private:
		vector<Record> records_;
};

#endif  /*PHONERECORDS_H*/

