/*!
 * \file	SharedLibrary_unix.h
 * \brief	Implementation for system abstraction of shared library
 * \author	Lucazeau Alexis - lucaze_b@epitech.eu
 * \version	0.1
 * \date	02/07/2010 11:25:07
 */

#ifndef		SHAREDLIBRARY_UNIX_H__
# define	SHAREDLIBRARY_UNIX_H__

# include	"ISharedLibrary.h"

/*!
 * \class	SharedLibrary_unix
 * \brief	Implementation for abstraction of shared library
 */
class		SharedLibrary_unix : public ISharedLibrary
{
	public:
		/*!
		 * \brief	Default constructor for SharedLibrary_unix
		 */
		SharedLibrary_unix();
		/*!
		 * \brief	Destructo for SharedLibrary_unix
		 */
		virtual ~SharedLibrary_unix();

		/*!
		 * \brief	Load library
		 * \param	Name of the library file to load
		 * \return	The handler of loaded library
		 */
		libHandler		libLoad(std::string const & filename);

		/*!
		 * \brief	Get pointer on function in a library
		 * \param	The handler of the library to search in
		 * \param	The name of the function to find out
		 * \return	The pointer of the found function
		 */
		libProcAddr		libGetProc(libHandler lib, std::string const & funcname);

		/*!
		 * \brief	Close and unmap the library from the memory
		 * \param	The handler of the library
		 * \return	true if success, false otherwise
		 */
		bool			libFree(libHandler lib);
};

typedef SharedLibrary_unix	SharedLibrary;

#endif		// SHAREDLIBRARY_UNIX_H__
