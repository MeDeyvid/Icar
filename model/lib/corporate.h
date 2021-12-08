#include <iostream>
#include <mysql/mysql.h>
#include <jsoncpp/json/json.h>
#include <string>
#include <ctime>

using namespace std;

class Corporate {
private:
  string id;
  string name;
  string cpf;
  string cnpj;
  string mail;
  string last_login;
  string address;
  string city;
  string state;
  string address_number;
  string corporate_name;
  string phone;
  string cell_phone;
  string city_id;
  string state_id;
  string country_id;
  int age;
  bool isLegal;
public:
  Corporate();
  ~Corporate();

  /* GETERS */
  string getId();

  string getName();

  string getCorporateName();

  string getCpf();

  string getCnpj();

  string getMail();

  string getAddress();

  string getAddressNumber();
  
  string getPhone();

  string getCellPhone();

  string getCityId();

  string getStateId();

  string getCountryId();

  bool getType();

  int getAge();

  /* SETTERS */
  void setId(const string &id);

  void setName(const string &name);

  void setCpf(const string &cpf);

  void setCnpj(const string &cnpj);

  void setMail(const string &mail);
  
  void setCity(const string &city);
  
  void setAddress(const string &address);
  
  void setState(const string &satate);

  void setType(const bool &isLegal);

  void setAge(const int &age);
  
  void setCorporateName(const string &corporate_name);
  
  void setPhone(const string &phone);
  
  void setCellPhone(const string &cell_phone);
  
  void setCityId(const string &city_id);
  
  void setStateId(const string &state_id);
  
  void setCoutryId(const string &coutry_id);
  
  void setAddressNumber(const string &address_number);

  void setParamsCorporate(Json::Value json);
};

string Corporate::getId() {return this->id;}

string Corporate::getName() {return this->name;}

string Corporate::getCorporateName() {return this->corporate_name;}

string Corporate::getCpf() {return this->cpf;}

string Corporate::getCnpj() {return this->cnpj;}

string Corporate::getMail() {return this->mail;}

string Corporate::getAddress() {return this->address;}

string Corporate::getAddressNumber() {return this->address_number;}

string Corporate::getCityId() {return this->city_id;}

string Corporate::getPhone() {return this->phone;}

string Corporate::getCellPhone() {return this->cell_phone;}

string Corporate::getStateId() {return this->state_id;}

string Corporate::getCountryId() {return this->country_id;}

bool Corporate::getType() {return this->isLegal;}

int Corporate::getAge() {return this->age;}

void Corporate::setId(const string &id) {this->id = id;}

void Corporate::setName(const string &name) {this->name = name;}

void Corporate::setCpf(const string &cpf) {this->cpf = cpf;}

void Corporate::setCnpj(const string &cnpj) {this->cnpj = cnpj;}

void Corporate::setMail(const string &mail) {this->mail = mail;}

void Corporate::setAddress(const string &address) {this->address = address;}

void Corporate::setState(const string &state) {this->state = state;}

void Corporate::setCity(const string &city) {this->city = city;}

void Corporate::setType(const bool &isLegal) {this->isLegal = isLegal;}

void Corporate::setAge(const int &age) {this->age = age;}

void Corporate::setCorporateName(const string &corporate_name) {this->corporate_name = corporate_name;}

void Corporate::setPhone(const string &phone) {this->phone = phone;}

void Corporate::setCellPhone(const string &cell_phone) {this->cell_phone = cell_phone;}

void Corporate::setCityId(const string &city_id) {this->city_id = city_id;}

void Corporate::setStateId(const string &state_id) {this->state_id = state_id;}

void Corporate::setCoutryId(const string &country_id) {this->country_id = country_id;}

void Corporate::setAddressNumber(const string &address_number) {this->address_number = address_number;}

Corporate::Corporate() {
  time_t now = time(0);
  this->last_login = ctime(&now);
}

Corporate::~Corporate() {
}

void Corporate::setParamsCorporate(Json::Value json) {
  this->setId(json["id"].asString());
  this->setName(json["name"].asString());
  this->setCorporateName(json["corporate_name"].asString());
  this->setPhone(json["phone"].asString());
  this->setCellPhone(json["cell_phone"].asString());
  this->setCityId(json["city_id"].asString());
  this->setStateId(json["state_id"].asString());
  this->setCoutryId(json["country_id"].asString());
  this->setAddress(json["address"].asString());
  this->setAddressNumber(json["address_number"].asString());
  this->setCnpj(json["address"].asString());
};
