#pragma once
#include "string";
using namespace std;
class UserModel
{
public:
	string nombre;
	string apellido;
	string usuario;
	string contrasena;
	string correo;

public:
	UserModel();
	~UserModel();
};

