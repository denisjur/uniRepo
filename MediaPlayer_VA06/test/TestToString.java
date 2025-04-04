import static org.junit.Assert.assertEquals;

import player.AudioFile;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * Tests for method AudioFile/toString()
 */

public class TestToString {
	private char sep;
	private String root = "/";
	private static boolean messageShown = false;
	
	@Before
	/**
	 * Setup operating system name and path separator.
	 * Choose either Windows or Linux - see comments below!
	 */
    public void setUp() {
		// to test Windows or Linux just use the corresponding lines in comments below
		// Windows: uncomment the next line
		//sep = Utils.emulateWindows();
		// Linux: uncomment the next line
		sep = Utils.emulateLinux();

        String osname = System.getProperty("os.name");
        if (!messageShown) {
        	System.out.printf("TestParsePathname: os name is %s, using path separator '%c'\n", osname, sep);
        	messageShown = true;
        }
        if (Utils.isWindows()) {
            root = "C:" + sep;
        }
	}

	@After
	public void tearDown() {
		Utils.resetEmulation();
	}

	@Test
	public void testToString01() {
		String pathname = "home" + sep 
				+  "meier" + sep 
				+  "Musik" + sep 
				+ "Falco - Rock Me Amadeus.mp3";
		String expectedToString = "Falco - Rock Me Amadeus";
		
		AudioFile af = new AudioFile(pathname);
		assertEquals("tostring result is not correct!", 
				expectedToString,
				af.toString());
	}

	@Test
	public void testToString02() {
		String pathname = root + "my-tmp" + sep + "file.mp3";
		String expectedToString = "file";
		
		AudioFile af = new AudioFile(pathname);
		assertEquals("tostring result is not correct!", 
				expectedToString,
				af.toString());
	}

	@Test
	public void testToString03() {
		String pathname = "";
		String expectedToString = "";
		
		AudioFile af = new AudioFile(pathname);
		assertEquals("tostring result is not correct!", 
				expectedToString,
				af.toString());
	}

	@Test
	public void testToString04() {
		String pathname = " - ";
		String expectedToString = "-";
		
		AudioFile af = new AudioFile(pathname);
		assertEquals("tostring result is not correct!", 
				expectedToString,
				af.toString());
	}

	@Test
	public void testToString05() {
		String pathname = "/MP3-Archiv/.nox";
		String expectedToString = "";
		
		AudioFile af = new AudioFile(pathname);
		assertEquals("tostring result is not correct!", 
				expectedToString,
				af.toString());
	}
}
