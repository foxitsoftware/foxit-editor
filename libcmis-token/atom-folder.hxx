/* libcmis
 * Version: MPL 1.1 / GPLv2+ / LGPLv2+
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License or as specified alternatively below. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * Major Contributor(s):
 * Copyright (C) 2011 SUSE <cbosdonnat@suse.com>
 *
 *
 * All Rights Reserved.
 *
 * For minor contributions see the git repository.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPLv2+"), or
 * the GNU Lesser General Public License Version 2 or later (the "LGPLv2+"),
 * in which case the provisions of the GPLv2+ or the LGPLv2+ are applicable
 * instead of those above.
 */
#ifndef _ATOM_FOLDER_HXX_
#define _ATOM_FOLDER_HXX_

#include <string>

#include "document.hxx"
#include "folder.hxx"
#include "atom-object.hxx"

class AtomFolder : public libcmis::Folder, public AtomObject
{
    public:
        AtomFolder( AtomPubSession* session, xmlNodePtr entryNd );
        ~AtomFolder( );

        // virtual pure methods from Folder
        virtual std::vector< libcmis::ObjectPtr > getChildren( ) throw ( libcmis::Exception );

        virtual libcmis::FolderPtr createFolder( const std::map< std::string, libcmis::PropertyPtr >& properties )
            throw ( libcmis::Exception );
        virtual libcmis::DocumentPtr createDocument( const std::map< std::string, libcmis::PropertyPtr >& properties,
                                boost::shared_ptr< std::ostream > os, std::string contentType, std::string fileName ) throw ( libcmis::Exception );

        virtual std::vector< std::string > removeTree( bool allVersion = true,
                                libcmis::UnfileObjects::Type unfile = libcmis::UnfileObjects::Delete,
                                bool continueOnError = false ) throw ( libcmis::Exception );

		virtual void setFolderProgressCallback(progressCallback pProgressCallback);
};

#endif
