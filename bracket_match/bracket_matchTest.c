#include "testUtils.h"
#include <string.h>
#include <stdio.h>
#include "bracket_match.h"
#include "stack.h"
void test_bracket_match(){
	String actual;
	strcpy(actual,"{[()]}");
	ASSERT(1==bracketMatch(actual));
}

void test_2_bracket_match(){
	String actual;
	strcpy(actual,"{[(()]}");
	ASSERT(0==bracketMatch(actual));
}

void test_3_bracket_match(){
	String actual;
	strcpy(actual,")");
	ASSERT(0==bracketMatch(actual));
}
void test_4_bracket_match(){
	String actual;
	strcpy(actual,"){{{[]]");
	ASSERT(0==bracketMatch(actual));
}
void test_5_bracket_match(){
	String actual;
	strcpy(actual,"{[(manali)]}");
	ASSERT(1==bracketMatch(actual));
}
void test_6_bracket_match(){
	String actual;
	strcpy(actual,"{[(manali)kajal])}");
	ASSERT(0==bracketMatch(actual));
}
