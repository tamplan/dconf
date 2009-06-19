/*
 * Copyright © 2009 Codethink Limited
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of version 3 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * See the included COPYING file for more information.
 *
 * Authors: Ryan Lortie <desrt@desrt.ca>
 */

#ifndef _dconf_dbus_h_
#define _dconf_dbus_h_

#include "dconf-private-types.h"

typedef struct OPAQUE_TYPE__DConfDBusAsyncResult            DConfDBusAsyncResult;

typedef void          (*DConfDBusAsyncReadyCallback)                    (DConfDBusAsyncResult         *result,
                                                                         gpointer                      user_data);
typedef void          (*DConfDBusNotify)                                (const gchar                  *path,
                                                                         const gchar * const          *items,
                                                                         gint                          items_length,
                                                                         guint32                       sequence,
                                                                         gpointer                      user_data);

DConfDBus *             dconf_dbus_new                                  (const gchar                  *path,
                                                                         GError                      **error);

gboolean                dconf_dbus_set                                  (DConfDBus                    *bus,
                                                                         const gchar                  *path,
                                                                         GVariant                     *value,
                                                                         guint32                      *sequence,
                                                                         GError                      **error);

void                    dconf_dbus_merge_tree_async                     (DConfDBus                    *bus,
                                                                         const gchar                  *prefix,
                                                                         GTree                        *values,
                                                                         DConfDBusAsyncReadyCallback   callback,
                                                                         gpointer                      user_data);

gboolean                dconf_dbus_merge_finish                         (DConfDBusAsyncResult         *result,
                                                                         guint32                      *sequence,
                                                                         GError                      **error);

void                    dconf_dbus_watch                                (DConfDBus                    *bus,
                                                                         const gchar                  *prefix,
                                                                         DConfDBusNotify               callback,
                                                                         gpointer                      user_data);
void                    dconf_dbus_unwatch                              (DConfDBus                    *bus,
                                                                         const gchar                  *prefix,
                                                                         DConfDBusNotify               callback,
                                                                         gpointer                      user_data);


#endif /* _dconf_dbus_h_ */