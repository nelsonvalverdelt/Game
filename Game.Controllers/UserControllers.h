#pragma once
#include <vector>
#include "..\Game.Models\UserModel.h"

using namespace std;
class UserController {
private:
	vector<UserModel> listUsers;
public:
	void CreateUser(UserModel user) {
		listUsers.push_back(user);
	}

	void GetUsers() {
		if (!listUsers.empty()) {
			listUsers.pop_back();
	}

	
		
	}
};