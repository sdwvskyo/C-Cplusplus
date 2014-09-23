#include "PhoneRecords.h"

void Record::setAll(const string &phone, const string &name, const string &address)
{
	phone_ = phone;
	name_ = name;
	address_ = address;
}

void Record::printRecord() const
{
	using std::cout;
	using std::endl;
	cout << "Name: " << name_ << " ";
	cout << "Phone: " << phone_ << " ";
	cout << "Address: " << address_ << endl;
}

void PhoneRecords::addRecord(const Record &record)
{
	records_.push_back(record);
}

void PhoneRecords::addRecord(const string &phone, 
							 const string &name, 
							 const string &address)
{
	Record record(phone, name, address);
	records_.push_back(record);
}

Record PhoneRecords::deleteRecord(const string &phone)
{
	Record result;
	vector<Record>::iterator it = records_.begin();
	while (it != records_.end()) {
		if (it->getPhone() == phone) {
			result = *it;
			it = records_.erase(it);
			break;
		}
		++it;
	}
	return result;
}

vector<Record> PhoneRecords::findByName(const string &name) const
{
	vector<Record> result;
	for (size_t ix = 0; ix < records_.size(); ++ix) {
		if (records_[ix].getName() == name)
			result.push_back(records_[ix]);
	}
	return result;
}

vector<Record> PhoneRecords::findByAddress(const string &address) const
{
	vector<Record> result;
	for (size_t ix = 0; ix < records_.size(); ++ix) {
		if (records_[ix].getAddress() == address)
			result.push_back(records_[ix]);
	}
	return result;

}
Record PhoneRecords::findByPhoneNo(const string &phone) const
{
	Record result;
	for (size_t ix = 0; ix < records_.size(); ++ix) {
		if (records_[ix].getPhone() == phone) {
			result = records_[ix];
			break;
		}
	}
	return result;
}

void PhoneRecords::printRecords() const
{
	vector<Record>::const_iterator it = records_.begin();
	while (it != records_.end()) {
		it->printRecord();
		++it;
	}
	std::cout << "-----------------------" << std::endl;
}
