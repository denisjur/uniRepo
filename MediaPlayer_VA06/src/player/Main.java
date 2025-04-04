
package player;

public class Main {
    public static void main(String[] args) {
        // Testăm clasa AudioFile cu diferite căi de fișiere
        AudioFile file1 = new AudioFile("C:\\Music\\Queen - Bohemian Rhapsody.mp3");
        System.out.println("Pathname: " + file1.getPathname());
        System.out.println("Filename: " + file1.getFilename());
        System.out.println("Author: " + file1.getAuthor());
        System.out.println("Title: " + file1.getTitle());
        System.out.println("Formatted: " + file1);

        System.out.println("----------------------");

        AudioFile file2 = new AudioFile("/home/user/Music/Eminem - Lose Yourself.mp3");
        System.out.println("Pathname: " + file2.getPathname());
        System.out.println("Filename: " + file2.getFilename());
        System.out.println("Author: " + file2.getAuthor());
        System.out.println("Title: " + file2.getTitle());
        System.out.println("Formatted: " + file2);

        System.out.println("----------------------");

        AudioFile file3 = new AudioFile("Metallica - Nothing Else Matters.mp3");
        System.out.println("Pathname: " + file3.getPathname());
        System.out.println("Filename: " + file3.getFilename());
        System.out.println("Author: " + file3.getAuthor());
        System.out.println("Title: " + file3.getTitle());
        System.out.println("Formatted: " + file3);
        
        AudioFile af = new AudioFile();
        af.parsePathname("Z:\\part1\\\\file.mp3\\");
        System.out.println();
        
        
        
    }
}