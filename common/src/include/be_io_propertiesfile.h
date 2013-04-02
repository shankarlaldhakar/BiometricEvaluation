/*
 * This software was developed at the National Institute of Standards and
 * Technology (NIST) by employees of the Federal Government in the course
 * of their official duties. Pursuant to title 17 Section 105 of the
 * United States Code, this software is not subject to copyright protection
 * and is in the public domain. NIST assumes no responsibility whatsoever for
 * its use by other parties, and makes no guarantees, expressed or implied,
 * about its quality, reliability, or any other characteristic.
 */

#ifndef __BE_IO_PROPERTIESFILE_H__
#define __BE_IO_PROPERTIESFILE_H__

#include <map>
#include <string>

#include <be_io.h>
#include <be_io_properties.h>
#include <be_error_exception.h>

using namespace std;

namespace BiometricEvaluation
{
	namespace IO
	{
		/**
		 * @brief
		 * A Properties object persisted in an file on disk.
		 * @details
		 * An example file might look like this:
		 * \verbatim
		 *     Name = John Smith
		 *     Age = 32
		 *     Favorite Hex Number = 0xffff
		 * \endverbatim
		 *
		 * For property keys and values, leading and trailing whitespace
		 * is removed, therefore the call 
		 * \code
		 *     props->setProperty("  My property   ", "   A Value  ");
		 * \endcode
		 * results in an entry in the property file as
		 * \verbatim
		 *     My property = A value
		 * \endverbatim
		 *
		 * Therefore, the property names "Foo", "  Foo", "Foo  " are 
		 * equivalent.
		 */
		class PropertiesFile : public Properties
		{
		public:			
			/**
			 * @brief
			 * Construct a new Properties object from an existing
			 * or to be created properties file. The constructor
			 * will create the file when it does not exist.
			 *
			 * @param[in] filename
			 *	The name of the file to store the properties.
			 * @param[in] mode
			 * 	The read/write mode of the object.
			 * @throw Error::StrategyError
			 *	A line in the properties file is malformed.
			 * @throw Error::FileError
			 *	An error occurred when using the underlying
			 *	storage system.
			 */
			PropertiesFile(
			    const string &filename,
			    uint8_t mode = IO::READWRITE)
			    throw (Error::FileError, 
			    Error::StrategyError);
			    

			/**
			 * @brief
			 * Write the properties to the underlying file,
			 * synchronizing the in-memory and on-disk versions.
			 *
			 * @throw Error::FileError
			 *	An error occurred when using the underlying
			 *	storage system.
			 * @throw Error::StrategyError
			 *	The object was constructed with NULL as the
			 *	file name, or is read-only.
			 */
			void
			sync()
			    throw (Error::FileError,
			    Error::StrategyError);

			/**
			 * @brief
			 * Change the name of the Properties, which means
			 * changing the name of the underlying file that stores
			 * the properties. The empty string ("") can be used
			 * to indicate no backing file.
			 * @note
			 * No check is made that the file is writeable at this
			 * time.
			 *
			 * @param[in] filename
			 *	The name of the properties file.
			 *
			 * @throw Error::StrategyError
			 *	The object is read-only.
			 */
			void
			changeName(
			    const string &filename)
			    throw (Error::StrategyError);
			
			/** Destructor */
			~PropertiesFile();

		protected:

		private:
			/**
			 * @brief
			 * Copy constructor (disabled).
			 * @details
			 * Disabled because this object could represent a
			 * file on disk.
			 *
			 * @param other
			 *	PropertiesFile object to copy.
			 */
			PropertiesFile(
			    const PropertiesFile &other);
			    
			/**
			 * @brief
			 * Assignment operator (disabled).
			 * @details
			 * Disabled because this object could represent a
			 * file on disk.
			 *
			 * @param other
			 *	PropertiesFile object to assign;
			 *
			 * @return
			 *	This PropertiesFile object, now containing
			 *	the contents of other.
			 */
			PropertiesFile&
			operator=(
			    const PropertiesFile &other);

			/** The file name of the underlying properties file */
			string _filename;
		};
	}
}
#endif	/* __BE_IO_PROPERTIESFILE_H__ */
