#ifndef		SHAREDLIBRARY_UNIX_H__
# define	SHAREDLIBRARY_UNIX_H__

# include	"ISharedLibrary.h"

class		SharedLibrary_unix : public ISharedLibrary
{
	public:
		SharedLibrary_unix();
		virtual ~SharedLibrary_unix();

		libHandler		libLoad(std::string const & filename);
		libProcAddr		libGetProc(libHandler lib, std::string const & funcname);
		bool			libFree(libHandler lib);
};

typedef SharedLibrary_unix	SharedLibrary;

#endif		// SHAREDLIBRARY_UNIX_H__
