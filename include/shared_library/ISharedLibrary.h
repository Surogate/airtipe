#ifndef		ISHAREDLIBRARY_H__
# define	ISHAREDLIBRARY_H__

# include	<string>

# ifdef		UNIX
	typedef	void* libHandler;
	typedef	void* libProcAddr;
# endif
# ifdef		WIN32
	typedef	HMODULE libHandler;
	typedef	FARPROC libProcAddr;
# endif

class		ISharedLibrary
{
	public:
		virtual libHandler		libLoad(std::string const & filename) = 0;
		virtual libProcAddr		libGetProc(libHandler lib, std::string const & funcname) = 0;
		virtual bool			libFree(libHandler lib) = 0;
};

#endif		// ISHAREDLIBRARY_H__
