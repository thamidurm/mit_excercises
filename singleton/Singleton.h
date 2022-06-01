#pragma once

class Singleton 
{
public:

	static Singleton& getInstance() 
	{
		return s_instance;
	}

private:
	Singleton(){}
	Singleton(const Singleton&) = delete;
	static Singleton s_instance;
};

Singleton Singleton::s_instance;
