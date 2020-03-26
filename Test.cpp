// AUTHOR: <Ariel saadon>

#include "doctest.h"
#include "PhoneticFinder.hpp"
#include <string>

using namespace phonetic;
using namespace std;


TEST_CASE("Test replacement of o and u && of d and t") {
    string text = "Dond vorri be haffy";
    CHECK(find(text, "tond") == string("Dond"));
    CHECK(find(text, "Dund") == string("Dond"));
    CHECK(find(text, "Dont") == string("Dond"));
    CHECK(find(text, "tund") == string("Dond"));
    CHECK(find(text, "tunt") == string("Dond"));
    CHECK(find(text, "Dunt") == string("Dond"));
}

TEST_CASE("Test replacement of v and w && o and u && i and y") {
    string text = "Dond vorri be haffy";
    CHECK(find(text, "worri") == string("vorri"));
    CHECK(find(text, "vurri") == string("vorri"));
    CHECK(find(text, "vorry") == string("vorri"));
    CHECK(find(text, "wurri") == string("vorri"));
    CHECK(find(text, "worry") == string("vorri"));
    CHECK(find(text, "wurry") == string("vorri"));
    CHECK(find(text, "vurry") == string("vorri"));
}

TEST_CASE("Test replacement of b and f and p") {
    string text = "Dond vorri be haffy";
    CHECK(find(text, "fe") == string("be"));
    CHECK(find(text, "pe") == string("be"));
}

TEST_CASE("Test replacement of b and f and p && i and y") {
    string text = "Dond vorri be haffy";
    CHECK(find(text, "habfy") == string("haffy"));
    CHECK(find(text, "hapfy") == string("haffy"));
    CHECK(find(text, "hafby") == string("haffy"));
    CHECK(find(text, "hafpy") == string("haffy"));
    CHECK(find(text, "habbi") == string("haffy"));
    CHECK(find(text, "happi") == string("haffy"));
    CHECK(find(text, "habby") == string("haffy"));
    CHECK(find(text, "happy") == string("haffy"));
    CHECK(find(text, "habfy") == string("haffy"));
    CHECK(find(text, "hapfy") == string("haffy"));
    CHECK(find(text, "hafby") == string("haffy"));
    CHECK(find(text, "hafpy") == string("haffy"));
}

TEST_CASE("Test equal word") {
    string text = "Dond vorri be haffy";
    CHECK(find(text, "Dond") == string("Dond"));
    CHECK(find(text, "vorri") == string("vorri"));
    CHECK(find(text, "be") == string("be"));
    CHECK(find(text, "haffy") == string("haffy"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Dond vorri be haffy";
    CHECK(find(text, "dond") == string("Dond"));
    CHECK(find(text, "DOnd") == string("Dond"));
    CHECK(find(text, "DONd") == string("Dond"));
    CHECK(find(text, "DOND") == string("Dond"));
    CHECK(find(text, "dOND") == string("Dond"));
    CHECK(find(text, "doND") == string("Dond"));
    CHECK(find(text, "donD") == string("Dond"));
    CHECK(find(text, "DonD") == string("Dond"));
    CHECK(find(text, "dOnD") == string("Dond"));
    CHECK(find(text, "DoNd") == string("Dond"));
}

TEST_CASE("Test replacement of s and z && t and d && j and g") {
    string text = "Ztrengths are dasqs or aktyons";
    CHECK(find(text, "strengths") == string("Ztrengths"));
    CHECK(find(text, "Zdrengths") == string("Ztrengths"));
    CHECK(find(text, "Ztrenjths") == string("Ztrengths"));
    CHECK(find(text, "Ztrengdhs") == string("Ztrengths"));
    CHECK(find(text, "Ztrengdhz") == string("Ztrengths"));
    CHECK(find(text, "sdrengths") == string("Ztrengths"));
    CHECK(find(text, "sdrenjths") == string("Ztrengths"));
    CHECK(find(text, "sdrenjdhs") == string("Ztrengths"));
    CHECK(find(text, "sdrenjdhz") == string("Ztrengths"));
    CHECK(find(text, "Zdrenjths") == string("Ztrengths"));
    CHECK(find(text, "Zdrenjdhs") == string("Ztrengths"));
    CHECK(find(text, "Zdrenjdhz") == string("Ztrengths"));
    CHECK(find(text, "Ztrenjdhs") == string("Ztrengths"));
    CHECK(find(text, "Ztrenjdhz") == string("Ztrengths"));
    CHECK(find(text, "Ztrengdhz") == string("Ztrengths"));
    CHECK(find(text, "strenjths") == string("Ztrengths"));
    CHECK(find(text, "strenjdhs") == string("Ztrengths"));
    CHECK(find(text, "strenjdhz") == string("Ztrengths"));
    CHECK(find(text, "strengdhs") == string("Ztrengths"));
    CHECK(find(text, "strengdhz") == string("Ztrengths"));
    CHECK(find(text, "strengthz") == string("Ztrengths"));
    CHECK(find(text, "Zdrenjths") == string("Ztrengths"));
    CHECK(find(text, "Zdrenjdhs") == string("Ztrengths"));
    CHECK(find(text, "Zdrenjdhz") == string("Ztrengths"));
    CHECK(find(text, "Zdrengdhs") == string("Ztrengths"));
    CHECK(find(text, "Zdrengdhz") == string("Ztrengths"));
    CHECK(find(text, "Zdrengthz") == string("Ztrengths"));
    CHECK(find(text, "Ztrenjdhs") == string("Ztrengths"));
    CHECK(find(text, "Ztrenjdhz") == string("Ztrengths"));
    CHECK(find(text, "Ztrenjthz") == string("Ztrengths"));
    CHECK(find(text, "Ztrengdhz") == string("Ztrengths"));
    CHECK(find(text, "strenjthz") == string("Ztrengths"));
    CHECK(find(text, "sdrengdhz") == string("Ztrengths"));
    CHECK(find(text, "sdrengdhs") == string("Ztrengths"));
    CHECK(find(text, "Ztrenjthz") == string("Ztrengths"));
}

TEST_CASE("Test replacement of s and z && t and d && c and k and q") {
    string text = "Ztrengths are dasqs or aktyons";
    CHECK(find(text, "tasqs") == string("dasqs"));
    CHECK(find(text, "dazqs") == string("dasqs"));
    CHECK(find(text, "dasks") == string("dasqs"));
    CHECK(find(text, "dascs") == string("dasqs"));
    CHECK(find(text, "dasqz") == string("dasqs"));
    CHECK(find(text, "tazqs") == string("dasqs"));
    CHECK(find(text, "tazks") == string("dasqs"));
    CHECK(find(text, "tazcs") == string("dasqs"));
    CHECK(find(text, "tazkz") == string("dasqs"));
    CHECK(find(text, "tazcz") == string("dasqs"));
    CHECK(find(text, "dazks") == string("dasqs"));
    CHECK(find(text, "dazcs") == string("dasqs"));
    CHECK(find(text, "dazkz") == string("dasqs"));
    CHECK(find(text, "dazcz") == string("dasqs"));
    CHECK(find(text, "daskz") == string("dasqs"));
    CHECK(find(text, "dascz") == string("dasqs"));
    CHECK(find(text, "tasks") == string("dasqs"));
    CHECK(find(text, "tascs") == string("dasqs"));
    CHECK(find(text, "tasqz") == string("dasqs"));
    CHECK(find(text, "tazqz") == string("dasqs"));
}

TEST_CASE("Test replacement of s and z && t and d && c and k and q") {
    string text = "Ztrengths are dasqs or aktyons";
    CHECK(find(text, "actyons") == string("aktyons"));
    CHECK(find(text, "aqtyons") == string("aktyons"));
    CHECK(find(text, "akdyons") == string("aktyons"));
    CHECK(find(text, "aktions") == string("aktyons"));
    CHECK(find(text, "aktyuns") == string("aktyons"));
    CHECK(find(text, "aktyonz") == string("aktyons"));
    CHECK(find(text, "acdyons") == string("aktyons"));
    CHECK(find(text, "aqdyons") == string("aktyons"));
    CHECK(find(text, "acdions") == string("aktyons"));
    CHECK(find(text, "aqdiuns") == string("aktyons"));
    CHECK(find(text, "acdiuns") == string("aktyons"));
    CHECK(find(text, "aqdiunz") == string("aktyons"));
    CHECK(find(text, "acdiunz") == string("aktyons"));
    CHECK(find(text, "akdiuns") == string("aktyons"));
    CHECK(find(text, "akdions") == string("aktyons"));
    CHECK(find(text, "akdiunz") == string("aktyons"));
    CHECK(find(text, "aktiuns") == string("aktyons"));
    CHECK(find(text, "aktiunz") == string("aktyons"));
    CHECK(find(text, "aktyunz") == string("aktyons"));
    CHECK(find(text, "aqtionz") == string("aktyons"));
    CHECK(find(text, "acdyonz") == string("aktyons"));
    CHECK(find(text, "akdiuns") == string("aktyons"));
    CHECK(find(text, "akdyonz") == string("aktyons"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Ztrengths are dasqs or aktyons";
    CHECK(find(text, "ZtRengths") == string("Ztrengths"));
    CHECK(find(text, "ZtrenGths") == string("Ztrengths"));
    CHECK(find(text, "ZtrengthS") == string("Ztrengths"));
    CHECK(find(text, "ZtrEngThs") == string("Ztrengths"));
    CHECK(find(text, "ZTrengthS") == string("Ztrengths"));
    CHECK(find(text, "ZtREnGths") == string("Ztrengths"));
    CHECK(find(text, "ZtRengTHs") == string("Ztrengths"));
    CHECK(find(text, "Dasqs") == string("dasqs"));
    CHECK(find(text, "DasqS") == string("dasqs"));
    CHECK(find(text, "dAsQs") == string("dasqs"));
    CHECK(find(text, "DAsQs") == string("dasqs"));
    CHECK(find(text, "DasQS") == string("dasqs"));
    CHECK(find(text, "AktYons") == string("aktyons"));
    CHECK(find(text, "AkTyOnS") == string("aktyons"));
    CHECK(find(text, "aKtYoNs") == string("aktyons"));
    CHECK(find(text, "aktyONs") == string("aktyons"));
    CHECK(find(text, "aKTyONs") == string("aktyons"));
    CHECK(find(text, "aRe") == string("are"));
    CHECK(find(text, "ArE") == string("are"));
    CHECK(find(text, "oR") == string("or"));
}