/****************************************************************************
 * NCSA HDF								    *
 * Software Development Group						    *
 * National Center for Supercomputing Applications			    *
 * University of Illinois at Urbana-Champaign				    *
 * 605 E. Springfield, Champaign IL 61820				    *
 *									    *
 * For conditions of distribution and use, see the accompanying		    *
 * hdf/COPYING file.							    *
 *									    *
 ****************************************************************************/

/*
 * This file contains private information about the H5D module
 */
#ifndef _H5Dprivate_H
#define _H5Dprivate_H

#include <H5Dpublic.h>

/* Private headers needed by this file */
#include <H5private.h>
#include <H5Fprivate.h>		/*for the H5F_t type			     */
#include <H5Gprivate.h>		/*symbol tables				     */
#include <H5Oprivate.h>		/*object Headers			     */
#include <H5Sprivate.h>		/*for the H5S_t type			     */
#include <H5Tprivate.h>		/*for the H5T_t type			     */

/*
 * Feature: Define H5D_DEBUG on the compiler command line if you want to
 *	    debug dataset I/O. NDEBUG must not be defined in order for this
 *	    to have any effect.
 */
#ifdef NDEBUG
#  undef H5D_DEBUG
#endif

#define H5D_RESERVED_ATOMS  0

/* Set the minimum object header size to create objects with */
#define H5D_MINHDR_SIZE 512

/* Dataset creation property list */
typedef struct H5D_create_t {
    H5D_layout_t	layout;		/*storage layout		     */
    intn		chunk_ndims;	/*chunk dimensionality		     */
    hsize_t		chunk_size[32];	/*chunk size if chunked storage	     */
    H5O_efl_t		efl;		/*external file list		     */
    H5O_pline_t		pline;		/*data filter pipeline		     */
} H5D_create_t;

/* Dataset transfer property list */
typedef struct H5D_xfer_t {
    size_t		buf_size;	/*max temp buffer size		     */
    void		*tconv_buf;	/*type conversion buffer or null     */
    void		*bkg_buf;	/*background buffer or null	     */
    H5T_bkg_t		need_bkg;	/*type of background buffer needed   */
    uintn       cache_hyper;    /* Whether to (try to) cache hyperslab blocks during I/O */
    uintn       block_limit;    /* The largest hyperslab block to try to cache */
    H5D_transfer_t	xfer_mode;	/*independent or collective transfer */
} H5D_xfer_t;

typedef struct H5D_t H5D_t;
extern const H5D_create_t H5D_create_dflt;
extern const H5D_xfer_t H5D_xfer_dflt;

/* Functions defined in H5D.c */
H5D_t *H5D_create (H5G_entry_t *loc, const char *name, const H5T_t *type,
		   const H5S_t *space, const H5D_create_t *create_parms);
H5D_t *H5D_open (H5G_entry_t *loc, const char *name);
herr_t H5D_close (H5D_t *dataset);
herr_t H5D_read (H5D_t *dataset, const H5T_t *mem_type,
		 const H5S_t *mem_space, const H5S_t *file_space,
		 const H5D_xfer_t *xfer_parms, void *buf/*out*/);
herr_t H5D_write (H5D_t *dataset, const H5T_t *mem_type,
		  const H5S_t *mem_space, const H5S_t *file_space,
		  const H5D_xfer_t *xfer_parms, const void *buf);
hid_t H5D_find_name (hid_t file_id, H5I_group_t UNUSED, const char *name);
herr_t H5D_extend (H5D_t *dataset, const hsize_t *size);
H5G_entry_t *H5D_entof (H5D_t *dataset);
H5T_t *H5D_typeof (H5D_t *dset);
H5S_t *H5D_get_space(H5D_t *dset);

#endif
