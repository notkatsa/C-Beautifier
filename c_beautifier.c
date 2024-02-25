#include <stdio.h>
int main(){
	int lastch = 32, quotes = 0, /* inhash = 0, */ open = 0, done, apostr = 0, blocks = 0, ch, whsp = 0, stline = 1;
	while ((ch = getchar()) != EOF) {
		done = 0;
		if (ch == ' ' || ch == '\t' || ch == '\n'){
			whsp = 1;
			continue; //all defautlt spaces turnt into whitespace
		}
		if (lastch != '\\' && ch == '"'){
			quotes++;
		}
		else if (lastch != '\\' && ch == '\'') {
			apostr++;
		}
		else if (lastch == '\\' && ch == '\\') {
			putchar('\\');
			lastch = 'a'; // 2 * \ -> cancels itself
			continue;
		}
		if (quotes == 2 || apostr == 2) {
			quotes = 0;
			apostr = 0;
		 /* if aftakia or aftaki reaches 2 then we are outside of a string so we reset it*/
		}
		if (quotes == 0 && apostr == 0) { // if outside of " "
			if (ch == '#'){
				putchar(ch);
				while ((ch = getchar()) != '\n') {
					putchar(ch);
				}
				putchar(ch);
				continue;
			}
			else if (ch == ')'){
				open++; // open parentheses ++
			}
			else if (ch == '('){
				open--;
			}
			else if ((ch == '{' || ch == '}') || ((ch == ';' || ch == '>') && open == 0)) {
				if (ch == '}')
					blocks--;
				if (stline == 1) {
					for (int i = 0 ; i < blocks ; i++) { // puts right amount of \t
						putchar('\t');
					}
					done = 1; // done flag so it doesn't get done again
				}
				if (ch == '{') {
					putchar(' ');
					blocks++;
				}
				putchar(ch);
				putchar('\n');
				whsp = 0;
				stline = 1;
				continue;
			}

		}
		if (stline == 1 && done != 1) { // incase it wasn't done earlier     
			for (int i = 0 ; i < blocks ; i++) {
				putchar('\t');
			}
		}
		if (whsp == 1 && stline == 0) {
			putchar(' ');
		}
		whsp = 0;
		stline = 0;
		putchar(ch);
		lastch = ch;
	}
}
