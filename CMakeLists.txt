cmake_minimum_required(VERSION 3.5)

project(prolab-2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(prolab-2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET prolab-2 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(prolab-2 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(prolab-2
            ${PROJECT_SOURCES}
            user.h user.cpp
            admin.h admin.cpp
            company.h company.cpp
            customer.h customer.cpp
            vehicle.h vehicle.cpp
            bus.h bus.cpp
            train.h train.cpp
            airplane.h airplane.cpp
            trip.h trip.cpp
            route.h route.cpp
            person.h person.cpp
            personel.h personel.cpp
            passenger.h passenger.cpp
            reservation.h reservation.cpp
            transport.h transport.cpp
            iloginable.h iloginable.cpp
            ireservable.h ireservable.cpp
            iprofitable.h iprofitable.cpp
            adminlogin.ui
            adminlogin.h adminlogin.cpp adminlogin.ui
            adminlogin.h adminlogin.cpp adminlogin.ui
            adminpage.h adminpage.cpp adminpage.ui
            companylogin.h companylogin.cpp companylogin.ui
            companypage.h companypage.cpp companypage.ui
            companylogin.h companylogin.cpp companylogin.ui
            companypage.h companypage.cpp companypage.ui
            userpage.h userpage.cpp userpage.ui
            seferbul.h seferbul.cpp seferbul.ui
            mywidget.h mywidget.cpp mywidget.ui
            vehicleseat.h vehicleseat.cpp vehicleseat.ui
            odemeekrani.h odemeekrani.cpp odemeekrani.ui




        )
    endif()
endif()

target_link_libraries(prolab-2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.prolab-2)
endif()
set_target_properties(prolab-2 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS prolab-2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(prolab-2)
endif()
