#pragma once
#include <vector>
#include <string>
#include "Auto.h"
using namespace std;
using namespace autos;

namespace kunde {
	class Kunde {
	private:
		string name;
	public:
		Kunde() {
			this->name = "lucica";
		}
		Kunde(const string& _name) {
			this->name = _name;
		}
		string get_name() const {
			return this->name;
		};
		~Kunde() {
		}
	};
}