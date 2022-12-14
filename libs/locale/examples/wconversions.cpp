//
// Copyright (c) 2009-2011 Artyom Beilis (Tonkikh)
//
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

//
// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !
//
// BIG FAT WARNING FOR Microsoft Visual Studio Users
//
// YOU NEED TO CONVERT THIS SOURCE FILE ENCODING TO UTF-8 WITH BOM ENCODING.
//
// Unfortunately MSVC understands that the source code is encoded as
// UTF-8 only if you add useless BOM in the beginning.
//
// So, before you compile "wide" examples with MSVC, please convert them to text
// files with BOM. There are two very simple ways to do it:
//
// 1. Open file with Notepad and save it from there. It would convert
//    it to file with BOM.
// 2. In Visual Studio go File->Advances Save Options... and select
//    Unicode (UTF-8  with signature) Codepage 65001
//
// Note: once converted to UTF-8 with BOM, this source code would not
// compile with other compilers, because no-one uses BOM with UTF-8 today
// because it is absolutely meaningless in context of UTF-8.
//
// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !
//
#include <boost/locale.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <iostream>

#include <ctime>


int main()
{
    using namespace boost::locale;
    // Create system default locale
    generator gen;
    std::locale loc=gen("");
    std::locale::global(loc);
    std::wcout.imbue(loc);

    // This is needed to prevent C library to
    // convert strings to narrow
    // instead of C++ on some platforms
    std::ios_base::sync_with_stdio(false);


    std::wcout << L"Correct case conversion can't be done by simple, character by character conversion\n";
    std::wcout << L"because case conversion is context sensitive and not 1-to-1 conversion\n";
    std::wcout << L"For example:\n";
    std::wcout << L"   German grüßen correctly converted to "
               << to_upper(L"grüßen") << L", instead of incorrect "
               << boost::to_upper_copy(std::wstring(L"grüßen")) << std::endl;
    std::wcout << L"     where ß is replaced with SS\n";
    std::wcout << L"   Greek ὈΔΥΣΣΕΎΣ is correctly converted to "
               << to_lower(L"ὈΔΥΣΣΕΎΣ") << L", instead of incorrect "
               << boost::to_lower_copy(std::wstring(L"ὈΔΥΣΣΕΎΣ")) << std::endl;
    std::wcout << L"     where Σ is converted to σ or to ς, according to position in the word\n";
    std::wcout << L"Such type of conversion just can't be done using std::toupper that work on character base, also std::toupper is \n";
    std::wcout << L"not fully applicable when working with variable character length like in UTF-8 or UTF-16 limiting the correct \n";
    std::wcout << L"behavoir to BMP or ASCII only\n";

}

// boostinspect:noascii
