/******************************************************************************
 * This software was developed at the National Institute of Standards and
 * Technology (NIST) by employees of the Federal Government in the course
 * of their official duties. Pursuant to title 17 Section 105 of the
 * United States Code, this software is not subject to copyright protection
 * and is in the public domain. NIST assumes no responsibility whatsoever for
 * its use by other parties, and makes no guarantees, expressed or implied,
 * about its quality, reliability, or any other characteristic.
 ******************************************************************************/
#ifndef __BE_IO_H__
#define __BE_IO_H__

/*
 * This file contains items that are used within the Biometric Evaluation
 * IO framework.
 */
namespace BiometricEvaluation {

	namespace IO {
			/*
			 * Constants that indicate the state of an object
			 * that manages some underlying file. This object
			 * may be read-only, or read-write.
			 */
			static const uint8_t READWRITE = 0;
			static const uint8_t READONLY = 1;
	}
}
#endif	/* __BE_IO_H__ */