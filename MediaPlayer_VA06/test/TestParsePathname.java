import static org.junit.Assert.assertEquals;

import player.AudioFile;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * Tests for method AudioFile/parsePathname()
 */
public class TestParsePathname {
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
	public void testParsePathname01() {
		String pathname = "home" + sep 
				+  "meier" + sep 
				+  "Musik" + sep 
				+ "Falco - Rock Me Amadeus.mp3";
		String expectedPathname = "home" + sep 
				+  "meier" + sep 
				+  "Musik" + sep 
				+ "Falco - Rock Me Amadeus.mp3";
		String expectedFilename = "Falco - Rock Me Amadeus.mp3";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname02() {
		String pathname = "home" + sep + "db-admin" + sep + "Frankie Goes To Hollywood - The Power Of Love.ogg";
		String expectedPathname = "home" + sep + "db-admin" + sep + "Frankie Goes To Hollywood - The Power Of Love.ogg";
		String expectedFilename = "Frankie Goes To Hollywood - The Power Of Love.ogg";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname03() {
		String pathname = root + "tmp" + sep + "Deep Purple - Smoke On The Water.wav";
		String expectedPathname = root + "tmp" + sep + "Deep Purple - Smoke On The Water.wav";
		String expectedFilename = "Deep Purple - Smoke On The Water.wav";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname04() {
		String pathname = root + "my-tmp" + sep + "file.mp3";
		String expectedPathname = root + "my-tmp" + sep + "file.mp3";
		String expectedFilename = "file.mp3";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname05() {
		String pathname = "Falco - Rock Me Amadeus.mp3";
		String expectedPathname = "Falco - Rock Me Amadeus.mp3";
		String expectedFilename = "Falco - Rock Me Amadeus.mp3";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname06() {
		String pathname = "file.mp3";
		String expectedPathname = "file.mp3";
		String expectedFilename = "file.mp3";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname07() {
		String pathname = ".." + sep + "music" + sep + "audiofile.au";
		String expectedPathname = ".." + sep + "music" + sep + "audiofile.au";
		String expectedFilename = "audiofile.au";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname08() {
		String pathname = "   A.U.T.O.R   -   T.I.T.E.L   .EXTENSION";
		String expectedPathname = "A.U.T.O.R   -   T.I.T.E.L   .EXTENSION";
		String expectedFilename = "A.U.T.O.R   -   T.I.T.E.L   .EXTENSION";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname09() {
		String pathname = "Hans-Georg Sonstwas - Blue-eyed boy-friend.mp3";
		String expectedPathname = "Hans-Georg Sonstwas - Blue-eyed boy-friend.mp3";
		String expectedFilename = "Hans-Georg Sonstwas - Blue-eyed boy-friend.mp3";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname10() {
		String pathname = "";
		String expectedPathname = "";
		String expectedFilename = "";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname11() {
		String pathname = " ";
		String expectedPathname = "";
		String expectedFilename = "";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname12() {
		String pathname = "//your-tmp/part1//file.mp3/";
		String expectedPathname = sep + "your-tmp" + sep + "part1" + sep + "file.mp3" + sep; 
		String expectedFilename = "";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname13() {
		String pathname = "../your-tmp/..//part1//file.mp3/";
		String expectedPathname = ".." + sep + "your-tmp" + sep + ".." 
				+ sep + "part1" + sep + "file.mp3" + sep;
		String expectedFilename = "";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname14() {
		String pathname = "\\file.mp3";
		String expectedPathname = sep + "file.mp3";
		String expectedFilename = "file.mp3";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname15() {
		String pathname = "\\part1\\\\file.mp3\\";
		String expectedPathname = sep + "part1" + sep + "file.mp3" + sep;
		String expectedFilename = "";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname16() {
		String pathname = "\\part1///file.mp3";
		String expectedPathname = sep + "part1" + sep + "file.mp3";
		String expectedFilename = "file.mp3";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname17() {
		String pathname = "/MP3-Archiv/.nox";
		String expectedPathname = sep + "MP3-Archiv" + sep + ".nox";
		String expectedFilename = ".nox";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}


	@Test
	public void testParsePathname18() {
		String pathname = "/MP3-Archiv/Falco - Rock me Amadeus.";
		String expectedPathname = sep + "MP3-Archiv" + sep + "Falco - Rock me Amadeus.";
		String expectedFilename = "Falco - Rock me Amadeus.";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname19() {
		String pathname = "-";
		String expectedPathname = "-";
		String expectedFilename = "-";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}

	@Test
	public void testParsePathname20() {
		String pathname = " -  ";
		String expectedPathname = "-";
		String expectedFilename = "-";
		
		AudioFile af = new AudioFile();
		af.parsePathname(pathname);
		assertEquals("Pathname not correct!", 
				expectedPathname,
				af.getPathname());
		assertEquals("Filename is not correct!!",
				expectedFilename,
				af.getFilename());
	}
}
