#ifndef DARKTABLE_IOP_COLOROUT_H
#define DARKTABLE_IOP_COLOROUT_H

#include "develop/imageop.h"
#include "iop/colorin.h" // common structs
#include <gtk/gtk.h>
#include <inttypes.h>
#include <lcms.h>

typedef struct dt_iop_colorout_global_data_t
{
  guint8 *data;
  gint data_size;
}
dt_iop_colorout_global_data_t;

typedef struct dt_iop_colorout_params_t
{
  char iccprofile[DT_IOP_COLOR_ICC_LEN];
  char displayprofile[DT_IOP_COLOR_ICC_LEN];
  dt_iop_color_intent_t intent;
  dt_iop_color_intent_t displayintent;
}
dt_iop_colorout_params_t;

typedef struct dt_iop_colorout_gui_data_t
{
  GtkVBox *vbox1, *vbox2;
  GtkLabel *label1, *label2, *label3, *label4;
  GtkComboBox *cbox1, *cbox2, *cbox3, *cbox4;
  GList *profiles;
}
dt_iop_colorout_gui_data_t;

typedef struct dt_iop_colorout_data_t
{
  cmsHPROFILE output;
  cmsHPROFILE Lab;
  cmsHTRANSFORM xform;
}
dt_iop_colorout_data_t;

void init(dt_iop_module_t *module);
void cleanup(dt_iop_module_t *module);

void gui_update    (struct dt_iop_module_t *self);
void commit_params (struct dt_iop_module_t *self, dt_iop_params_t *params, dt_dev_pixelpipe_t *pipe, dt_dev_pixelpipe_iop_t *piece);
void init_pipe     (struct dt_iop_module_t *self, dt_dev_pixelpipe_t *pipe, dt_dev_pixelpipe_iop_t *piece);
void reset_params  (struct dt_iop_module_t *self, dt_dev_pixelpipe_t *pipe, dt_dev_pixelpipe_iop_t *piece);
void cleanup_pipe  (struct dt_iop_module_t *self, dt_dev_pixelpipe_t *pipe, dt_dev_pixelpipe_iop_t *piece);

void gui_init     (struct dt_iop_module_t *self);
void gui_cleanup  (struct dt_iop_module_t *self);

void process (struct dt_iop_module_t *self, dt_dev_pixelpipe_iop_t *piece, void *i, void *o, const dt_iop_roi_t *roi_in, const dt_iop_roi_t *roi_out);

#endif
