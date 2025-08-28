cmake_minimum_required(VERSION 3.16)

project(NotepadPlus VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core5Compat)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets PrintSupport)

set(PROJECT_SOURCES
        main.cpp
        fusionnote.cpp
        fusionnote.h
        fusionnote.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(NotepadPlus
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Resources.qrc
        helper_file.h helper_file.cpp

        helper_status_bar.h helper_status_bar.cpp

        helper_font_text.h helper_font_text.cpp
        helper_theme.h helper_theme.cpp
        infowindow.h infowindow.cpp infowindow.ui
        findwindow.h findwindow.cpp findwindow.ui
        replacewindow.h replacewindow.cpp replacewindow.ui
        helper_image.h helper_image.cpp
        rtfparser.h rtfparser.cpp







    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET NotepadPlus APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(NotepadPlus SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(NotepadPlus
            ${PROJECT_SOURCES}
        )
    endif()
endif()


target_link_libraries(NotepadPlus PRIVATE
    Qt6::Core5Compat
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::PrintSupport
)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.NotepadPlus)
endif()
set_target_properties(NotepadPlus PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS NotepadPlus
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(NotepadPlus)
endif()
