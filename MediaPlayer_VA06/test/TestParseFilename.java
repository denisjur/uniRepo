import static org.junit.Assert.assertEquals;

import player.AudioFile;

import org.junit.Before;
import org.junit.Test;

/**
 * Tests for method AudioFile/parseFilename()
 */
public class TestParseFilename {
	
	@Test
	public void testParseFilename01() {
		String filename = "Falco - Rock Me Amadeus.mp3";
		String expectedAuthor = "Falco";
		String expectedTitle = "Rock Me Amadeus";
		
		AudioFile af = new AudioFile();
		af.parseFilename(filename);
		assertEquals("Author is not correct!", 
				expectedAuthor,
				af.getAuthor());
		assertEquals("Title is not correct!",
				expectedTitle,
				af.getTitle());
	}

	@Test
	public void testParseFilename02() {
		String filename = "Frankie Goes To Hollywood - The Power Of Love.ogg";
		String expectedAuthor = "Frankie Goes To Hollywood";
		String expectedTitle = "The Power Of Love";
		
		AudioFile af = new AudioFile();
		af.parseFilename(filename);
		assertEquals("Author is not correct!", 
				expectedAuthor,
				af.getAuthor());
		assertEquals("Title is not correct!",
				expectedTitle,
				af.getTitle());
	}

	@Test
	public void testParseFilename03() {
		String filename = "file.mp3";
		String expectedAuthor = "";
		String expectedTitle = "file";
		
		AudioFile af = new AudioFile();
		af.parseFilename(filename);
		assertEquals("Author is not correct!", 
				expectedAuthor,
				af.getAuthor());
		assertEquals("Title is not correct!",
				expectedTitle,
				af.getTitle());
	}

	@Test
	public void testParseFilename04() {
		String filename = "A.U.T.O.R   -   T.I.T.E.L   .EXTENSION";
		String expectedAuthor = "A.U.T.O.R";
		String expectedTitle = "T.I.T.E.L";
		
		AudioFile af = new AudioFile();
		af.parseFilename(filename);
		assertEquals("Author is not correct!", 
				expectedAuthor,
				af.getAuthor());
		assertEquals("Title is not correct!",
				expectedTitle,
				af.getTitle());
	}

	@Test
	public void testParseFilename05() {
		String filename = "Hans-Georg Sonstwas - Blue-eyed boy-friend.mp3";
		String expectedAuthor = "Hans-Georg Sonstwas";
		String expectedTitle = "Blue-eyed boy-friend";
		
		AudioFile af = new AudioFile();
		af.parseFilename(filename);
		assertEquals("Author is not correct!", 
				expectedAuthor,
				af.getAuthor());
		assertEquals("Title is not correct!",
				expectedTitle,
				af.getTitle());
	}

	@Test
	public void testParseFilename06() {
		String filename = "";
		String expectedAuthor = "";
		String expectedTitle = "";
		
		AudioFile af = new AudioFile();
		af.parseFilename(filename);
		assertEquals("Author is not correct!", 
				expectedAuthor,
				af.getAuthor());
		assertEquals("Title is not correct!",
				expectedTitle,
				af.getTitle());
	}

	@Test
	public void testParseFilename07() {
		String filename = " ";
		String expectedAuthor = "";
		String expectedTitle = "";
		
		AudioFile af = new AudioFile();
		af.parseFilename(filename);
		assertEquals("Author is not correct!", 
				expectedAuthor,
				af.getAuthor());
		assertEquals("Title is not correct!",
				expectedTitle,
				af.getTitle());
	}

	@Test
	public void testParseFilename08() {
		String filename = ".nox";
		String expectedAuthor = "";
		String expectedTitle = "";
		
		AudioFile af = new AudioFile();
		af.parseFilename(filename);
		assertEquals("Author is not correct!", 
				expectedAuthor,
				af.getAuthor());
		assertEquals("Title is not correct!",
				expectedTitle,
				af.getTitle());
	}

	@Test
	public void testParseFilename09() {
		String filename = "Falco - Rock me Amadeus.";
		String expectedAuthor = "Falco";
		String expectedTitle = "Rock me Amadeus";
		
		AudioFile af = new AudioFile();
		af.parseFilename(filename);
		assertEquals("Author is not correct!", 
				expectedAuthor,
				af.getAuthor());
		assertEquals("Title is not correct!",
				expectedTitle,
				af.getTitle());
	}

	@Test
	public void testParseFilename10() {
		String filename = "-";
		String expectedAuthor = "";
		String expectedTitle = "-";
		
		AudioFile af = new AudioFile();
		af.parseFilename(filename);
		assertEquals("Author is not correct!", 
				expectedAuthor,
				af.getAuthor());
		assertEquals("Title is not correct!",
				expectedTitle,
				af.getTitle());
	}

	@Test
	public void testParseFilename11() {
		String filename = " - ";
		String expectedAuthor = "";
		String expectedTitle = "";
		
		AudioFile af = new AudioFile();
		af.parseFilename(filename);
		assertEquals("Author is not correct!", 
				expectedAuthor,
				af.getAuthor());
		assertEquals("Title is not correct!",
				expectedTitle,
				af.getTitle());
	}
}
