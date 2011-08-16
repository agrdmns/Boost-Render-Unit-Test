This is set of files that will be used to render the output from the Boost Unit Testing framework.

The script `render_boost_test` takes, as its main argument, the compiled binary from a boost unit test. It runs the test and creates a file containing the output in XML. If desired, it can then render the output in a web browser, using the XSL definition in `render_test.xsl` and the stylesheet in `render_test.xsl`.

The sample directory contains a sample test put together from 
[Boost Test Examples](https://github.com/jsankey/boost.test-examples). To see how this works first compile the test. Assuming your boost library is installed in `/usr/local`, compile it with
    
     g++ -I/usr/local/include -L/usr/local/lib -lboost_unit_test_framework sample_test.cpp -o sample_test

Now run the script to render the test output in a browser.

    ./render_boost_test -t sample_test -x render_test.xsl -d

*Note: a screen shot is included to show what the output looks like when rendered in a browser.*

Make sure to look at the help for more information and explanations of the options to the script.

    ./render_boost_test --help

One useful option specifies which browser to use for viewing the output. Google Chrome doesn't seem to like the XML file created, so another browser can be used with the `--browser`

    ./render_boost_test -t sample_test -x render_test.xsl -d --browser Safari.app
