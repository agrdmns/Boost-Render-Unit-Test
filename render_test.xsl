<!-- <?xml version="1.0" encoding="UTF-8"?> -->
<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->
<!-- - boost unit testing -->
<!-- -  -->
<!-- - render_test.xsl -->
<!-- -	XSL spec for rendering the output from a boost unit test -->
<!-- -  -->
<!-- - 2011-08-16  Created by Sean Lynch -->
<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->
<xsl:stylesheet
    version="1.0" 
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns="http://www.w3.org/1999/xhtml">
  <xsl:output method="html" />

  <xsl:template match="/TestLog">
    <html>
      <head>
        <title>Sample Unit Test Output</title>
	<link rel="stylesheet" href="render_test.css" type="text/css" media="screen" />
      </head>
      <body>
        <div id="main">
          <h1>Sample Unit Test Output</h1>
	  <br />
	  <!-- Loop through all the standalone test cases  -->
          <xsl:for-each select="TestSuite/TestCase">
            <div class="case">
              Test Case: <xsl:value-of select="@name" /> (<xsl:value-of select="TestingTime" />ms)
              <xsl:for-each select="child::node()">
                <xsl:choose>
                  <xsl:when test="self::Error|self::FatalError|self::Exception">
                    <div class="fail">
                      <xsl:value-of select="@file" />, line: <xsl:value-of select="@line" />
                      <p><xsl:value-of select="." /></p>
                    </div>
                  </xsl:when>
                  <xsl:when test="self::Info">
                    <div class="pass">
                      <p><xsl:value-of select="." /></p>
                    </div>
                  </xsl:when>
                  <xsl:when test="self::Message">
                    <div class="message">
                      <p><xsl:value-of select="." /></p>
                    </div>
                  </xsl:when>
                </xsl:choose>
              </xsl:for-each>
            </div>
          </xsl:for-each>
          
          <xsl:for-each select="TestSuite/TestSuite">
            <div id="suite">
              Test Suite: <xsl:value-of select="@name" />

	      <!-- Loop through all the suite test cases  -->
              <xsl:for-each select="TestCase">
                <div class="case">
                  Test Case: <xsl:value-of select="@name" /> (<xsl:value-of select="TestingTime" />ms)
                  <xsl:for-each select="child::node()">
                    <xsl:choose>
                      <xsl:when test="self::Error|self::FatalError|self::Exception">
                        <div class="fail">
                          <xsl:value-of select="@file" />, line: <xsl:value-of select="@line" />
                          <p><xsl:value-of select="." /></p>
                        </div>
                      </xsl:when>
                      <xsl:when test="self::Info">
                        <div class="pass">
                          <p><xsl:value-of select="." /></p>
                        </div>
                      </xsl:when>
                      <xsl:when test="self::Message">
                        <div class="message">
                          <p><xsl:value-of select="." /></p>
                        </div>
                      </xsl:when>
                    </xsl:choose>
                  </xsl:for-each>
                </div>
              </xsl:for-each>
              
            </div>
          </xsl:for-each>
        </div>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>

<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->
<!-- - render_test.xsl                                                           -->
<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->