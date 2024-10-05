#include <iostream>
#include <string>
#include <vector>
#include <utility>

class RealObject {
protected:
	static std::vector<RealObject*> objs;

	std::unique_ptr<std::string> name;

public:
	RealObject() {
		name = std::unique_ptr<std::string>(new std::string);
		objs.push_back(this);
	}

	~RealObject() {
		objs.erase(findObj(*name.get()));
	}

	std::string getName() const noexcept {
		return *name;
	}

	static std::vector<RealObject*>::const_iterator findObj(const std::string& name) {
		auto it = objs.begin();
		for (; it != objs.end(); it++)
			if ((*it)->getName() == name)
				break;
		return it;
	}

	void Pernut() const noexcept {
		std::cout << "ПППППППППППУУУУУУУУУУУУУУУУУУУУУУУККККККККККККК!!!!!!!!!!!!!!!!!" << std::endl;
	}
};

std::vector<RealObject*> RealObject::objs;

class Arbuz : public RealObject {
public:
	Arbuz() {
		*name = "Арбуз";
	}

	Arbuz(const std::string& name) {
		*this->name = name;
	}
};

class Person : public RealObject {
	std::unique_ptr<std::string> friend_name;

public:
	Person() {
		friend_name = std::unique_ptr<std::string>(new std::string);
	}

	void Pozdorovatsa(const RealObject& obj) noexcept {
		*friend_name = obj.getName();
		std::cout << *friend_name << ", " << *friend_name << ", " << "привет!" << std::endl;
	}

	void PoprositPernut() const noexcept {
		std::cout << *friend_name << ", " << *friend_name << ", " << "пёрни!" << std::endl;
		(*RealObject::findObj(*friend_name))->Pernut();
	}
};

int main() {
	std::setlocale(LC_ALL, ".UTF8");

	Arbuz arbuz;
	Person person;

	person.Pozdorovatsa(arbuz);
	person.PoprositPernut();

	return 0;
}
