#include <stdio.h>
#include <stdbool.h>

int main() {
    int lastch = 32; // Last character processed, initialized to space
    bool inString = false, inChar = false; // Flags for string and character literals
    int blocks = 0; // Block depth
    int ch; // Current character
    bool stline = true; // Start of a new line flag
    
    while ((ch = getchar()) != EOF) {
        bool done = false; // Flag indicating if the character was processed


        // Toggle inString flag for double quotes not preceded by a backslash
        if (lastch != '\\' && ch == '"') {
            inString = !inString;
        }
        // Toggle inChar flag for single quotes not preceded by a backslash
        else if (lastch != '\\' && ch == '\'') {
            inChar = !inChar;
        }
        // Handle escaping backslashes
        else if (lastch == '\\' && ch == '\\') {
            putchar('\\');
            lastch = 'a'; // Use a placeholder to mark the escape
            continue;
        }

        // Processing outside of strings and character literals
        if (!inString && !inChar) {
            if (ch == '#') {
                // Print current character and the rest of the line
                putchar(ch);
                while ((ch = getchar()) != '\n' && ch != EOF) {
                    putchar(ch);
                }
                if (ch == '\n') {
                    putchar(ch);
                }
                continue;
            }
            else if (ch == '(') {
                blocks++; // Increment block depth for open parentheses
            }
            else if (ch == ')') {
                blocks--; // Decrement block depth for close parentheses
            }
            else if ((ch == '{' || ch == '}') || ((ch == ';' || ch == '>') && blocks == 0)) {
                if (ch == '}') {
                    blocks--; // Decrement block depth for close braces
                }
                if (stline) {
                    // Indentation for the start of a new line
                    for (int i = 0; i < blocks; i++) {
                        putchar('\t');
                    }
                    done = true; // Mark as processed
                }
                if (ch == '{') {
                    blocks++; // Increment block depth for open braces
                    putchar(' '); // Add space before opening brace
                }
                putchar(ch);
                putchar('\n'); // New line after special characters
                stline = true; // Reset start of line flag
                continue;
            }
        }

        // Apply indentation at the start of a new line if not already done
        if (stline && !done) {
            for (int i = 0; i < blocks; i++) {
                putchar('\t');
            }
        }

        stline = false; // Clear start of line flag after processing a character
        putchar(ch); // Print the current character
        lastch = ch; // Update the last character processed
    }

    return 0;
}
