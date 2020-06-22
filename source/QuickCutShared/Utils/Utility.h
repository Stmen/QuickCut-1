
#pragma once

#include "Types.h"

namespace boost
{
    namespace property_tree
    {
        /*
         * Originally the boost::write_json function treats even numbers as strings, therefore
         * this function will parse the input and make the json file look as it should be.
         */
        void write_jsonEx(const std::string & path, const JSON & ptree);

        QString get(JSON & ptree, const QString & path, const QString & defaultValue);
        JSON &  put(JSON & ptree, const QString & path, const QString & value);
    } // namespace property_tree
} // namespace boost

namespace QuickCut
{
    QString getDateTime();
    QString createUuid();
} // namespace QuickCut
