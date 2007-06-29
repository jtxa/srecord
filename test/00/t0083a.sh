#!/bin/sh
#
#       srecord - manipulate eprom load files
#       Copyright (C) 2003, 2006, 2007 Peter Miller
#
#       This program is free software; you can redistribute it and/or modify
#       it under the terms of the GNU General Public License as published by
#       the Free Software Foundation; either version 2 of the License, or
#       (at your option) any later version.
#
#       This program is distributed in the hope that it will be useful,
#       but WITHOUT ANY WARRANTY; without even the implied warranty of
#       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#       GNU General Public License for more details.
#
#       You should have received a copy of the GNU General Public License
#       along with this program; if not, write to the Free Software
#       Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
#       02110-1301 USA.
#
# MANIFEST: Test the Cosmac functionality
#
here=`pwd`
if test $? -ne 0 ; then exit 2; fi
work=${TMP_DIR-/tmp}/$$

pass()
{
        cd $here
        rm -rf $work
        echo PASSED
        exit 0
}

fail()
{
        cd $here
        rm -rf $work
        echo 'FAILED test of the Cosmac functionality'
        exit 1
}

no_result()
{
        cd $here
        rm -rf $work
        echo 'NO RESULT for test of the Cosmac functionality'
        exit 2
}

trap "no_result" 1 2 3 15

bin=$here/${1-.}/bin
mkdir $work
if test $? -ne 0; then no_result; fi
cd $work
if test $? -ne 0; then no_result; fi

cat > test.in << 'fubar'
S0220000687474703A2F2F737265636F72642E736F75726365666F7267652E6E65742F1D
S12300004B33195800334FA288C4E25FD5D2113274295C8CC3AECB1CC0F79DB4D33B8E1FB2
S12300206EA7776EDAC611638AF3C260C5D39239FCEEC5C09C91DC5D8879115BB49F7A227B
S123004046F19021B7A184429446A259193492152258D5BFE9B11C712A2DCCDECC47001272
S1230060389133F032B732C7FDD4201608B32C2A0B01E9F4B30565DD3231BCFE78BC11B1A0
S12300804D44A180FCD347F9A76710AF1A3CD9253DC319F0C87ECEFBB08AF928460AD9944A
S12300A04F7A144B4D5B44F4C254A3DD907D02CE401CBE089A8C034A16FD735D074CF156AF
S10D00C0C705A11460E609223AAC5A
S12300CBCB290299691E5772B8E47503FA7276577AC248D0894D729EAD58A7D09253CF5D1E
S12300EB7DD1F6E6EF4E58A832CEAB2C402184BAE3CC8B6D1AFD0BC755B297E705674582CC
S123010B383B692889C1D0BB8F7BE8D09C6C8A7F3815EC5212F71A67A9B14FAF1894315189
S123012BCF9A79595C4914EBC4FCBB606846DFA15BCCF36EC30DD56DBF241CD7B84D2888A3
S123014BE8A1E144EAF52FAEF2EB0E5A31EEFB8CBAEFFA7DFCD0EABBF40693AD54BB353CF0
S123016B5D1680470BAFF6FD9A0458CBF25358AC42522A3F2214FA171B8DC46F49F9ABA6CD
S123018B0F2BED1ADAE31875E87040DAC3988706EBB1450DC53F24E0CDE84F16E1FABCF0D4
S12301AB25A90B008D23757593B54F564ED65C3987A1464DE16B2DAE537DC4357780259DB3
S12301CB29309DB653122BE6C77B3D1551994ED93B95261C0053CA53D08E88480EAEE537C1
S12301EBDE82EE329419185B945571E6EFBFBF2A54E546543810A8099E3051ACDE36E3BD2E
S123020BB8D1EF4CEB07A77F5D18654CD824762C09BC8142CC294B6A599C1638D2F9F58A70
S123022BCBE4D6B6EB7D3548969B946EBF0A9AC9C61B0B924456FC9EF212D6C40CCB4ED7E4
S123024BAF248D9AA1C2E3375D77A51D8240E6485BF1DBA047D73E39EA14FDF6DF4BCD8EC0
S123026B6F5A28101C0B487A83ED97052D7D4D896E2829B50067EEEA7BEBE05A36ADE8A536
S123028B0710B5231CFD9D9FEB34A418B1F1A11F1ACAD41A31C204ACADE406E391EE889840
S12302AC3EBB1B3B59BA268D5E3F3F4FE05E69AB3383DCF58789A36B8F86FC7E0F947D4DFB
S10D02CC509888A952AF36B0EE75C1
S12302D7CED4697907EC56FC74DF9FDF6E26DCEC35706982C0010A6953B9A003A715037665
S12302F7E96CEFF05845EDCC248CAC93B2887FE7F8E969B9EA74223E2DC241D5D8444BC1DC
S1220317B03AB209809FD5A42B8137DE09B7C502A02FBB8AA3DDC8D0A00AA5784EF039D4
S12303372BEB08AB8ADD4FB65F8794683E596ADE8825682B0331FCA33BA11B89925488BDEE
S1230357409068CA6EB780CD3E14357C6EA05AF6C5C322C8F41E6B2FBF86B851DB410E1BFC
S1230377D176E53F2E660C6C7A42E9E8E243DFA7060170FA1FDB29DE62E2303D233E58F4E3
S1230397B53D34E3A3404F1E823806647CE50C82E67C7D0557A6E4B98814F6AB524EA007D4
S12303B78CD4EA2F143A4D977254FBEE3907712083EE25DB9409941D1D8BC870D96877653B
S12303D73C6295519CE2E80E36E3FD70EB6E906E5CB549F0BFDE0DDC69D64C423EC4A87B6B
S10C03F7263DCCC21FB4D0569778
S5030022DA
S9030000FC
fubar
if test $? -ne 0; then no_result; fi

cat > test.ok << 'fubar'
!M0000 4B33195800334FA288C4E25FD5D2113274295C8CC3AECB1CC0F79DB4D33B8E1F6EA7776E,
DAC611638AF3C260C5D39239FCEEC5C09C91DC5D8879115BB49F7A2246F19021B7A184429446A2,
59193492152258D5BFE9B11C712A2DCCDECC470012389133F032B732C7FDD4201608B32C2A0B01,
E9F4B30565DD3231BCFE78BC11B14D44A180FCD347F9A76710AF1A3CD9253DC319F0C87ECEFBB0,
8AF928460AD9944F7A144B4D5B44F4C254A3DD907D02CE401CBE089A8C034A16FD735D074CF156,
C705A11460E609223AAC;
00CB CB290299691E5772B8E47503FA7276577AC248D0894D729EAD58A7D09253CF5D7DD1F6E6EF,
4E58A832CEAB2C402184BAE3CC8B6D1AFD0BC755B297E705674582383B692889C1D0BB8F7BE8D0,
9C6C8A7F3815EC5212F71A67A9B14FAF18943151CF9A79595C4914EBC4FCBB606846DFA15BCCF3,
6EC30DD56DBF241CD7B84D2888E8A1E144EAF52FAEF2EB0E5A31EEFB8CBAEFFA7DFCD0EABBF406,
93AD54BB353C5D1680470BAFF6FD9A0458CBF25358AC42522A3F2214FA171B8DC46F49F9ABA60F,
2BED1ADAE31875E87040DAC3988706EBB1450DC53F24E0CDE84F16E1FABCF025A90B008D237575,
93B54F564ED65C3987A1464DE16B2DAE537DC4357780259D29309DB653122BE6C77B3D1551994E,
D93B95261C0053CA53D08E88480EAEE537DE82EE329419185B945571E6EFBFBF2A54E546543810,
A8099E3051ACDE36E3BDB8D1EF4CEB07A77F5D18654CD824762C09BC8142CC294B6A599C1638D2,
F9F58ACBE4D6B6EB7D3548969B946EBF0A9AC9C61B0B924456FC9EF212D6C40CCB4ED7AF248D9A,
A1C2E3375D77A51D8240E6485BF1DBA047D73E39EA14FDF6DF4BCD8E6F5A28101C0B487A83ED97,
052D7D4D896E2829B50067EEEA7BEBE05A36ADE8A50710B5231CFD9D9FEB34A418B1F1A11F1ACA,
D41A31C204ACADE406E391EE8898;
02AC 3EBB1B3B59BA268D5E3F3F4FE05E69AB3383DCF58789A36B8F86FC7E0F947D4D509888A952,
AF36B0EE75;
02D7 CED4697907EC56FC74DF9FDF6E26DCEC35706982C0010A6953B9A003A7150376E96CEFF058,
45EDCC248CAC93B2887FE7F8E969B9EA74223E2DC241D5D8444BC1B03AB209809FD5A42B8137DE,
09B7C502A02FBB8AA3DDC8D0A00AA5784EF039;
0337 2BEB08AB8ADD4FB65F8794683E596ADE8825682B0331FCA33BA11B89925488BD409068CA6E,
B780CD3E14357C6EA05AF6C5C322C8F41E6B2FBF86B851DB410E1BD176E53F2E660C6C7A42E9E8,
E243DFA7060170FA1FDB29DE62E2303D233E58F4B53D34E3A3404F1E823806647CE50C82E67C7D,
0557A6E4B98814F6AB524EA0078CD4EA2F143A4D977254FBEE3907712083EE25DB9409941D1D8B,
C870D96877653C6295519CE2E80E36E3FD70EB6E906E5CB549F0BFDE0DDC69D64C423EC4A87B26,
3DCCC21FB4D05697
fubar
if test $? -ne 0; then no_result; fi

$bin/srec_cat test.in -o test.out -cosmac
if test $? -ne 0; then fail; fi

diff test.ok test.out
if test $? -ne 0; then fail; fi

#
# now test reading the Cosmsc format
#
$bin/srec_cmp test.in test.out -cosmac
if test $? -ne 0; then fail; fi

#
# The things tested here, worked.
# No other guarantees are made.
#
pass
