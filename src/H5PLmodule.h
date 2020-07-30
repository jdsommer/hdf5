/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the COPYING file, which can be found at the root of the source code       *
 * distribution tree, or in https://support.hdfgroup.org/ftp/HDF5/releases.  *
 * If you do not have access to either file, you may request a copy from     *
 * help@hdfgroup.org.                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * Purpose: This file contains declarations which define macros for the
 *          H5PL package.  Including this header means that the source file
 *          is part of the H5PL package.
 */

#ifndef _H5PLmodule_H
#define _H5PLmodule_H

/* Define the proper control macros for the generic FUNC_ENTER/LEAVE and error
 *      reporting macros.
 */
#define H5PL_MODULE
#define H5_MY_PKG       H5PL
#define H5_MY_PKG_ERR   H5E_PLUGIN
#define H5_MY_PKG_INIT  YES

/**\defgroup H5PL H5PL: Plugin Interface
   \todo Describe concisely what the functions in this module are about.
 */

#endif /* _H5PLmodule_H */
