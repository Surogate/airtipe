/*!
 * \file	ISharedLibrary.h
 * \brief	Interface for system abstraction of shared library
 * \author	Lucazeau Alexis - lucaze_b@epitech.eu
 * \version	0.1
 * \date	02/07/2010 11:25:07
 */

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

/*!
 * \class	ISharedLibrary
 * \brief	Interface for abstraction of shared library
 */
class		ISharedLibrary
{
	public:
		/*!
		 * \brief	Load library
		 * \param	Name of the library file to load
		 * \return	The handler of loaded library
		 */
		virtual libHandler		libLoad(std::string const & filename) = 0;

		/*!
		 * \brief	Get pointer on function in a library
		 * \param	The handler of the library to search in
		 * \param	The name of the function to find out
		 * \return	The pointer of the found function
		 */
		virtual libProcAddr		libGetProc(libHandler lib, std::string const & funcname) = 0;

		/*!
		 * \brief	Close and unmap the library from the memory
		 * \param	The handler of the library
		 * \return	true if success, false otherwise
		 */
		virtual bool			libFree(libHandler lib) = 0;
};

#endif		// ISHAREDLIBRARY_H__
