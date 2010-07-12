#include	<iostream>
#include	<dlfcn.h>
#include	"SharedLibrary_unix.h"

SharedLibrary_unix::SharedLibrary_unix()
{

}

SharedLibrary_unix::~SharedLibrary_unix()
{

}

libHandler		SharedLibrary_unix::libLoad(std::string const & filename)
{
	libHandler	lib = dlopen(filename.c_str(), RTLD_LAZY);
	if (lib == NULL)
	{
		std::cerr << "Fail to load shared library: " << filename << std::endl;
	}
	return (lib);
}

libProcAddr		SharedLibrary_unix::libGetProc(libHandler lib, std::string const & funcName)
{
	libProcAddr pfn = dlsym(lib, funcName.c_str());
	if (pfn == NULL)
	{
		std::cerr << "Fail to load shared function: " << funcName << std::endl;
	}
	return (pfn);
}

bool		SharedLibrary_unix::libFree(libHandler lib)
{
	int r = dlclose(lib);
	if (r == 0)
		return (true);
	return (false);
}
