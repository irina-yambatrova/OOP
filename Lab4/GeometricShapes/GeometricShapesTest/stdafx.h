// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



///**************************
#define BOOST_TEST_MODULE GeometricShapesTestsModule
#define BOOST_TEST_INCLUDED
#pragma warning (disable:4702)
#include <boost/test/unit_test.hpp>
///*************************



#include <iostream>
#include <boost/optional.hpp>
#include <string>
#include <vector>
