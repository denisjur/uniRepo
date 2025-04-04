package player;

public class TestAudioFile {
    private static char sep;
    private static String root = "/";
    
    private static char emulateWindows() {
        System.setProperty("os.name", "Windows");
        System.setProperty("file.separator", "\\");
        return '\\';
    }
    
    private static char emulateLinux() {
        System.setProperty("os.name", "Linux");
        System.setProperty("file.separator", "/");
        return '/';
    }
    
    private static boolean isWindows() {
        return System.getProperty("os.name").toLowerCase().indexOf("win") >= 0;
    }
    
    private static void setUp(boolean useWindows) {
        if (useWindows) {
            sep = emulateWindows();
        } else {
            sep = emulateLinux();
        }
        
        String osname = System.getProperty("os.name");
        System.out.printf("Test: sistem de operare este %s, separator de cale '%c'\n", osname, sep);
        
        if (isWindows()) {
            root = "C:" + sep;
        }
    }
    
    private static void assertEquals(String message, String expected, String actual) {
        if (expected.equals(actual)) {
            System.out.println("TEST REUȘIT: " + message);
        } else {
            System.out.println("TEST EȘUAT: " + message);
            System.out.println("  Așteptat: '" + expected + "'");
            System.out.println("  Actual:   '" + actual + "'");
        }
    }
    
    private static void testToString01() {
        String pathname = "home" + sep + "meier" + sep + "Musik" + sep + "Falco - Rock Me Amadeus.mp3";
        String expectedToString = "Falco - Rock Me Amadeus";
        
        AudioFile af = new AudioFile(pathname);
        assertEquals("Test 1: Verificarea metodei toString pentru un fișier cu cale completă", 
                expectedToString,
                af.toString());
    }
    
    private static void testToString02() {
        String pathname = root + "my-tmp" + sep + "file.mp3";
        String expectedToString = "file";
        
        AudioFile af = new AudioFile(pathname);
        assertEquals("Test 2: Verificarea metodei toString pentru un fișier fără autor", 
                expectedToString,
                af.toString());
    }
    
    private static void testToString03() {
        String pathname = "";
        String expectedToString = "";
        
        AudioFile af = new AudioFile(pathname);
        assertEquals("Test 3: Verificarea metodei toString pentru un pathname gol", 
                expectedToString,
                af.toString());
    }
    
    private static void testToString04() {
        String pathname = " - ";
        String expectedToString = "-";
        
        AudioFile af = new AudioFile(pathname);
        assertEquals("Test 4: Verificarea metodei toString pentru un pathname special", 
                expectedToString,
                af.toString());
    }
    
    private static void testToString05() {
        String pathname = "/MP3-Archiv/.nox";
        String expectedToString = "";
        
        AudioFile af = new AudioFile(pathname);
        assertEquals("Test 5: Verificarea metodei toString pentru un fișier ascuns", 
                expectedToString,
                af.toString());
    }
    
    /**
     * Testează metoda parsePathname
     */
    private static void testParsePathname() {
        System.out.println("\n=== TESTE PENTRU PARSE PATHNAME ===");
        
        // Test pentru un pathname gol
        AudioFile af1 = new AudioFile();
        af1.parsePathname("");
        assertEquals("Test pathname gol", "", af1.getPathname());
        assertEquals("Test pathname gol - filename", "", af1.getFilename());
        
        // Test pentru un fișier simplu
        AudioFile af2 = new AudioFile();
        af2.parsePathname("file.mp3");
        assertEquals("Test fișier simplu - pathname", "file.mp3", af2.getPathname());
        assertEquals("Test fișier simplu - filename", "file.mp3", af2.getFilename());
        
        // Test pentru cale cu spații
        AudioFile af3 = new AudioFile();
        String testPath = "  " + sep + "my-tmp" + sep + "file.mp3";
        String expectedPath = root + "my-tmp" + sep + "file.mp3";
        af3.parsePathname(testPath);
        assertEquals("Test cale cu spații - pathname", expectedPath, af3.getPathname());
        assertEquals("Test cale cu spații - filename", "file.mp3", af3.getFilename());
        
        // Test pentru separatori multipli
        AudioFile af4 = new AudioFile();
        String multiSepPath;
        String expectedMultiSepPath;
        if (isWindows()) {
            multiSepPath = "\\\\my-tmp\\\\\\part1\\\\file.mp3\\";
            expectedMultiSepPath = "\\my-tmp\\part1\\file.mp3\\";
        } else {
            multiSepPath = "//my-tmp////part1//file.mp3/";
            expectedMultiSepPath = "/my-tmp/part1/file.mp3/";
        }
        af4.parsePathname(multiSepPath);
        assertEquals("Test separatori multipli - pathname", expectedMultiSepPath, af4.getPathname());
        assertEquals("Test separatori multipli - filename", "", af4.getFilename());
    }
    
    private static void testParseFilename() {
        System.out.println("\n=== TESTE PENTRU PARSE FILENAME ===");
        

        AudioFile af1 = new AudioFile();
        af1.parseFilename("Falco - Rock Me Amadeus.mp3");
        assertEquals("Test filename normal - author", "Falco", af1.getAuthor());
        assertEquals("Test filename normal - title", "Rock Me Amadeus", af1.getTitle());
        

        AudioFile af2 = new AudioFile();
        af2.parseFilename(" Falco  -  Rock me   Amadeus .mp3 ");
        assertEquals("Test filename cu spații - author", "Falco", af2.getAuthor());
        assertEquals("Test filename cu spații - title", "Rock me   Amadeus", af2.getTitle());
        

        AudioFile af3 = new AudioFile();
        af3.parseFilename("audiofile.aux");
        assertEquals("Test filename fără autor - author", "", af3.getAuthor());
        assertEquals("Test filename fără autor - title", "audiofile", af3.getTitle());
        

        AudioFile af4 = new AudioFile();
        af4.parseFilename("   A.U.T.O.R   -   T.I.T.E.L  .EXTENSION");
        assertEquals("Test filename special - author", "A.U.T.O.R", af4.getAuthor());
        assertEquals("Test filename special - title", "T.I.T.E.L", af4.getTitle());
    }
    
    public static void main(String[] args) {
        // Testare pe Windows
        System.out.println("=== TESTARE PE WINDOWS ===");
        setUp(true);
        testToString01();
        testToString02();
        testToString03();
        testToString04();
        testToString05();
        testParsePathname();
        testParseFilename();
        
        // Testare pe Linux
        System.out.println("\n=== TESTARE PE LINUX ===");
        setUp(false);
        testToString01();
        testToString02();
        testToString03();
        testToString04();
        testToString05();
        testParsePathname();
        testParseFilename();
        
        System.out.println("\nTestarile sunt complete!");
    }
}