cmake_minimum_required (VERSION 3.16)

# Back compatibility for VERSION range
if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy (VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif ()

macro (package_add_test TESTNAME)
    # create an exectuable in which the tests will be stored
    add_executable (${TESTNAME} ${ARGN})
    # link the Google test infrastructure, mocking library, and a default main fuction to
    # the test executable.  Remove g_test_main if writing your own main function.
    target_include_directories (${TESTNAME} PUBLIC ${CMAKE_SOURCE_DIR}/include CONAN_PKG::boost)
    target_link_libraries (${TESTNAME} CONAN_PKG::gtest data-tools)
    # gtest_discover_tests replaces gtest_add_tests,
    # see https://cmake.org/cmake/help/v3.10/module/GoogleTest.html for more options to pass to it

    gtest_discover_tests (
        ${TESTNAME}
        # set a working directory so your project root so that you can find test data via paths relative to the project root
        SOURCES ${ARGN}
        WORKING_DIRECTORY ${PROJECT_DIR}
    )
    set_target_properties (${TESTNAME} PROPERTIES FOLDER tests)
endmacro ()

package_add_test (testSequence sequence.cpp)
package_add_test (testSort sort.cpp)
package_add_test (testBiTreeSequence bi_tree_sequence.cpp)
package_add_test (testSequenceIterator sequence_iterator.cpp)
package_add_test (testList list.cpp)
package_add_test (testMapSet map_set.cpp)
package_add_test (testBiTreeMap bi_tree_map.cpp)
package_add_test (testPriorityQueue priority_queue.cpp)
package_add_test (testOrderedStack ordered_stack.cpp)
package_add_test (testRB rb.cpp)
package_add_test (testLinkedStack linked_stack.cpp)
package_add_test (testLinkedTree linked_bi_tree.cpp)

