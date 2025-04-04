import static java.lang.reflect.Modifier.isFinal;
import static java.lang.reflect.Modifier.isPublic;
import static java.lang.reflect.Modifier.isStatic;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import java.lang.reflect.Field;

import player.AudioFile;

import org.junit.Test;

@SuppressWarnings("rawtypes")
public class AttributesTest {
    // Liste aller Klassen
    private Class[] clazzA = {
    	AudioFile.class,
    };
    
    private String[] attributeNames = {
    	"pathname", "filename", "author", "title"
    };

    @Test
    public void testAttributes() {
        // Teste alle Klassen im Array clazzA
        for (Class theClass : clazzA) {
            try {
                // Teste alle Attribute
                for (Field field : theClass.getDeclaredFields()) {
                    field.setAccessible(true);
                    String attShort = field.getName();

                    /** 
                     * Attribute names start with lowercase letters
                     * Exceptions:
                     * - synthetic attributes like Enum expansiones
                     * - constants defined with final modifier
                     */
                    assertTrue("Attribute "
                        + attShort
                        + ": Name of attribute should start with lower case letters",
                        Character.isLowerCase(attShort.charAt(0))
                        || field.isSynthetic()
                        || isFinal(field.getModifiers()));

                    /**
                     * Attributes should not be public
                     * Exceptions:
                     * - static attributes defined with static modifier
                     * - synthetic attributes
                     */
                    int mod = field.getModifiers();
                    assertTrue("attribute '" + attShort + "' should not be public!", 
                            !isPublic(mod) || isStatic(field.getModifiers()));
                }
            } catch (SecurityException e) {
                fail(e.toString());
            }
        }
    }
    
    @Test
    public void testGetters() {
    	for (String attributeName : attributeNames) {
    		try {
    			Field f = AudioFile.class.getDeclaredField(attributeName);
    			assertEquals("String", f.getType().getSimpleName());
    		} catch (NoSuchFieldException nsfe) {
    			fail("Attribute \"" + attributeName + "\" missing!");
    		}
    	}
    }
}
