import static org.junit.Assert.assertEquals;
import static org.junit.Assert.fail;

import java.lang.reflect.Modifier;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import player.AudioFile;

public class AudioFileTest {

    private static char sep;

    private static String root = "/";

    private static String pathNames[];

    private static String expectedPathNames[];

    private static String expectedFileNames[];

    private static String expectedAuthors[];

    private static String expectedTitles[];

    private static String expectedToStrings[];

    @Before
    public void setUp() {
		// to test Windows or Linux just use the corresponding lines in comments below
		// Windows: uncomment the next line
		// sep = Utils.emulateWindows();
		// Linux: uncomment the next line
		sep = Utils.emulateLinux();

        String osname = System.getProperty("os.name");
        if (osname.toLowerCase().indexOf("win") >= 0)
            root = "C:" + sep;

        // This array contains the arguments we feed to test method parsePathname()
        pathNames = new String[] {
                "home" + sep + "meier" + sep + "Musik" + sep + "Falco - Rock Me Amadeus.mp3",
                "home" + sep + "db-admin" + sep + "Frankie Goes To Hollywood - The Power Of Love.ogg",
                root + "tmp" + sep + "Deep Purple - Smoke On The Water.wav",
                root + "my-tmp" + sep + "file.mp3",
                "Falco - Rock Me Amadeus.mp3",
                "file.mp3",
                ".." + sep + "music" + sep + "audiofile.au",
                "   A.U.T.O.R   -   T.I.T.E.L   .EXTENSION",
                "Hans-Georg Sonstwas - Blue-eyed boy-friend.mp3",
                "",
                " ",
                "//your-tmp/part1//file.mp3/",
                "../your-tmp/..//part1//file.mp3/",
                "\\file.mp3",
                "\\part1\\\\file.mp3\\",
                "\\part1///file.mp3",
                "/MP3-Archiv/.nox",
                "/MP3-Archiv/Falco - Rock me Amadeus.",
                "-",
                " -  "
        };

        // Array of the results expected from method getPathname() 
        // We expect normalization with respect to consecutive occurrences of / and \
        // and replacement by a single System.getProperty("file.separator").charAt(0)
        expectedPathNames = new String[] {
                "home" + sep + "meier" + sep + "Musik" + sep + "Falco - Rock Me Amadeus.mp3",
                "home" + sep + "db-admin" + sep + "Frankie Goes To Hollywood - The Power Of Love.ogg",
                root + "tmp" + sep + "Deep Purple - Smoke On The Water.wav",
                root + "my-tmp" + sep + "file.mp3",
                "Falco - Rock Me Amadeus.mp3",
                "file.mp3",
                ".." + sep + "music" + sep + "audiofile.au",
                "A.U.T.O.R   -   T.I.T.E.L   .EXTENSION",
                "Hans-Georg Sonstwas - Blue-eyed boy-friend.mp3",
                "",
                "",
                sep + "your-tmp" + sep + "part1" + sep + "file.mp3" + sep,
                ".." + sep + "your-tmp" + sep + ".." + sep + "part1" + sep + "file.mp3" + sep,
                sep + "file.mp3",
                sep + "part1" + sep + "file.mp3" + sep,
                sep + "part1" + sep + "file.mp3",
                sep + "MP3-Archiv" + sep + ".nox",
                sep + "MP3-Archiv" + sep + "Falco - Rock me Amadeus.",
                "-",
                "-"
        };

        // Array of the results expected from method getFilename() 
        expectedFileNames = new String[] {
                "Falco - Rock Me Amadeus.mp3",
                "Frankie Goes To Hollywood - The Power Of Love.ogg",
                "Deep Purple - Smoke On The Water.wav",
                "file.mp3",
                "Falco - Rock Me Amadeus.mp3",
                "file.mp3",
                "audiofile.au",
                "A.U.T.O.R   -   T.I.T.E.L   .EXTENSION",
                "Hans-Georg Sonstwas - Blue-eyed boy-friend.mp3",
                // Some more ugly test cases
                "",
                "",
                "",
                "",
                "file.mp3",
                "",
                "file.mp3",
                ".nox",
                "Falco - Rock me Amadeus.",
                "-",
                "-"
        };

        // Array of the results expected from method getAuthor() 
        // Leading and trailing spaces and tabs (white space) are trimmed.
        expectedAuthors = new String[] {
                "Falco",
                "Frankie Goes To Hollywood",
                "Deep Purple",
                "",
                "Falco",
                "",
                "",
                "A.U.T.O.R",
                "Hans-Georg Sonstwas",
                // Some more ugly test cases
                "", 
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                "Falco",
                "",
                ""
        };

        // Array of the results expected from method getTitle() 
        // Leading and trailing spaces and tabs (white space) are trimmed.
        expectedTitles = new String[] {
                "Rock Me Amadeus",
                "The Power Of Love",
                "Smoke On The Water",
                "file",
                "Rock Me Amadeus",
                "file",
                "audiofile",
                "T.I.T.E.L",
                "Blue-eyed boy-friend",
                // Some more ugly test cases
                "",
                "",
                "",
                "",
                "file",
                "",
                "file",
                "",
                "Rock me Amadeus",
                "-",
                "-"
        };

        // Array of the results expected from method toString() 
        expectedToStrings = new String[] {
                "Falco - Rock Me Amadeus",
                "Frankie Goes To Hollywood - The Power Of Love",
                "Deep Purple - Smoke On The Water",
                "file",
                "Falco - Rock Me Amadeus",
                "file",
                "audiofile",
                "A.U.T.O.R - T.I.T.E.L",
                "Hans-Georg Sonstwas - Blue-eyed boy-friend",
                // Some more ugly test cases
                "",
                "",
                "",
                "",
                "file",
                "",
                "file",
                "",
                "Falco - Rock me Amadeus",
                "-",
                "-"
        };
    }

	@After
	public void tearDown() {
		Utils.resetEmulation();
	}
    
    /**
     *  Use the constructor without arguments
     */
    @Test
    public void testSettersAndGetters() {
        String current = null;
        try {
            for (int i = 0; i < pathNames.length; i++) {
                String p = pathNames[i];
                current = p;

                System.out.printf("testSettersAndGetters: pathname='%s'\nexpected:\n\tpathname='%s'\n\tfilename='%s'\n\tauthor='%s'\n\ttitle='%s'\n\ttoString='%s'\n",
                		p, expectedPathNames[i], expectedFileNames[i], expectedAuthors[i], expectedTitles[i], expectedToStrings[i]);
                AudioFile af = new AudioFile();
                af.parsePathname(p);
                af.parseFilename(af.getFilename());

                assertEquals("getPathname() for test case [" + i + "]: " + p
                        + " not correct", expectedPathNames[i],
                        af.getPathname());
                assertEquals("getFilename() for test case [" + i + "]: " + p
                        + " not correct", expectedFileNames[i],
                        af.getFilename());
                assertEquals("getAuthor() for test case [" + i + "]: " + p
                        + " not correct", expectedAuthors[i], af.getAuthor());
                assertEquals("getTitle() for test case [" + i + "]: " + p
                        + " not correct", expectedTitles[i], af.getTitle());
                assertEquals("toString() for test case [" + i + "]: " + p
                        + " not correct", expectedToStrings[i], af.toString());
            }
        } catch (Exception e) {
            e.printStackTrace();
            fail("Error for pathname:" + current + ":" + e);
        }
    }

    /**
     *  Perform the same getter and setter tests by using the CTOR with one
     *  argument for construction
     */
    @Test
    public void testCtor() {
        String current = null;
        try {
            for (int i = 0; i < pathNames.length; i++) {
                String p = pathNames[i];
                current = p;

                System.out.printf("testCtor: pathname='%s'\nexpected:\n\tpathname='%s'\n\tfilename='%s'\n\tauthor='%s'\n\ttitle='%s'\n\ttoString='%s'\n",
                		p, expectedPathNames[i], expectedFileNames[i], expectedAuthors[i], expectedTitles[i], expectedToStrings[i]);
                AudioFile af = new AudioFile(p);
                assertEquals("getPathname() for test case [" + i + "]: " + p
                        + " not correct", expectedPathNames[i],
                        af.getPathname());
                assertEquals("getFilename() for test case [" + i + "]: " + p
                        + " not correct", expectedFileNames[i],
                        af.getFilename());
                assertEquals("getAuthor() for test case [" + i + "]: " + p
                        + " not correct", expectedAuthors[i], af.getAuthor());
                assertEquals("getTitle() for test case [" + i + "]: " + p
                        + " not correct", expectedTitles[i], af.getTitle());
                assertEquals("toString() for test case [" + i + "]: " + p
                        + " not correct", expectedToStrings[i], af.toString());
            }
        } catch (Exception e) {
        	e.printStackTrace();
            fail("Error for pathname:" + current + ":" + e);
        }
    }

    /**
     *  A test case for the treatment of drive letters.
     *  If a drive specifier (a single letter followed by :)
     *  is provided it is to be replaced according to the platform.
     *  On windows:        d: --> d:  (no transformation of drive specifier)
     *  On other platform: d: --> /d/ or more precisely sep + "d" + sep
     */
    @Test
    public void test_TreatmentOfDriveLetters_01() {
        AudioFile af = new AudioFile();
        af.parsePathname("Z:\\part1\\\\file.mp3\\");

        char sep = System.getProperty("file.separator").charAt(0);

        if (isWindows()) {
            // On Windows we expect "Z:\part1\file.mp3\"
            assertEquals("Pathname stored incorrectly",
                    "Z:" + sep + "part1" + sep + "file.mp3" + sep,
                    af.getPathname());
        } else {
            // On other platforms we expect "/Z/part1/file.mp3/" 
            assertEquals("Pathname stored incorrectly",
                    sep + "Z" + sep + "part1" + sep + "file.mp3" + sep,
                    af.getPathname());
        }
        assertEquals("Returned filename is incorrect", "", af.getFilename());
    }

    /**
     * A test case for the treatment of drive letters
     */
    @Test
    public void test_TreatmentOfDriveLetters_02() {
        AudioFile af = new AudioFile();
        af.parsePathname("Z:///part1//file.mp3");

        char sep = System.getProperty("file.separator").charAt(0);

        if (isWindows()) {
            // On Windows we expect "Z:\part1\file.mp3"
            assertEquals("Pathname stored incorrectly", 
                    "Z:" + sep + "part1" + sep + "file.mp3",
                    af.getPathname());
        } else {
            // On other platforms we expect "/Z/part1/file.mp3/" 
            assertEquals("Pathname stored incorrectly",
                    sep + "Z" + sep + "part1" + sep + "file.mp3",
                    af.getPathname());
        }
        assertEquals("Returned filename is incorrect", "file.mp3", af.getFilename());
    }

    /**
     * A test case for the treatment of drive letters
     */
    @Test
    public void test_TreatmentOfDriveLetters_03() {
        AudioFile af = new AudioFile();
        af.parsePathname("Z:///file.mp3");

        char sep = System.getProperty("file.separator").charAt(0);

        if (isWindows()) {
            // On Windows we expect "Z:\file.mp3"
            assertEquals("Pathname stored incorrectly", 
                    "Z:" + sep + "file.mp3",
                    af.getPathname());
        } else {
            // On other platforms we expect "/Z/file.mp3" 
            assertEquals("Pathname stored incorrectly",
                    sep + "Z" + sep + "file.mp3",
                    af.getPathname());
        }
        assertEquals("Returned filename is incorrect", "file.mp3", af.getFilename());
    }
 
    @Test
    public void test_parsePathname_xy1() throws Exception {
        AudioFile af = new AudioFile();
        af.parsePathname("/part1/mymusic/ -");
        char sepchar = System.getProperty("file.separator").charAt(0);
        assertEquals("Pathname stored incorrectly", sepchar + "part1" + sepchar +
                    "mymusic" + sepchar + " -", af.getPathname());
        assertEquals("Returned filename is incorrect", "-", af.getFilename());
    }
    
    @Test
    public void test_parsePathname_xy2() throws Exception {
        AudioFile af = new AudioFile();
        af.parsePathname("\\nocheinsong\\- ");
        char sepchar = System.getProperty("file.separator").charAt(0);
        assertEquals("Pathname stored incorrectly", sepchar  +"nocheinsong" +
                    sepchar + "-", af.getPathname());
        assertEquals("Returned filename is incorrect", "-", af.getFilename());
    }

    /**
     * Checks if the required public interface of the class (and only this!) has
     * been implemented.
     */
    @Test
    public void test_PublicInterface_AllowedMethods() {
    	String[] allowedNames = {
    		"parsePathname",
    		"parseFilename",
    		"getPathname",
    		"getFilename",
    		"getAuthor",
    		"getTitle",
    		"toString",
    		"main" // may be used for testing
    	};
    	TestUtils.checkAllowedAccessableMethods(AudioFile.class, allowedNames);
    }

    /**
     * Checks if the signatures of the allowed methods are correct.
     */
    @Test
    public void test_PublicInterface_Signatures() {
    	TestUtils.checkMethod(
        		AudioFile.class, 
        		Modifier.PUBLIC, 
        		"parsePathname", 
        		void.class, 
        		new Class<?>[] { String.class });
        	
    	TestUtils.checkMethod(
        		AudioFile.class, 
        		Modifier.PUBLIC, 
        		"parseFilename", 
        		void.class, 
        		new Class<?>[] { String.class });
        	
    	TestUtils.checkMethod(
        		AudioFile.class, 
        		Modifier.PUBLIC, 
        		"getPathname", 
        		String.class, 
        		new Class<?>[] {});
        	
    	TestUtils.checkMethod(
        		AudioFile.class, 
        		Modifier.PUBLIC, 
        		"getFilename", 
        		String.class, 
        		new Class<?>[] {});
        	
    	TestUtils.checkMethod(
        		AudioFile.class, 
        		Modifier.PUBLIC, 
        		"getAuthor", 
        		String.class, 
        		new Class<?>[] {});
        	
    	TestUtils.checkMethod(
        		AudioFile.class, 
        		Modifier.PUBLIC, 
        		"getTitle", 
        		String.class, 
        		new Class<?>[] {});        	

    	TestUtils.checkMethod(
        		AudioFile.class, 
        		Modifier.PUBLIC, 
        		"toString", 
        		String.class, 
        		new Class<?>[] {});
        	
    }

    /*
     * Auxiliary methods 
     */

     private boolean isWindows() {
        return System.getProperty("os.name").toLowerCase().indexOf("win") >= 0;
    }
}
