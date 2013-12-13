#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_for_creating_stack");
	setup();
		test_for_creating_stack();
	tearDown();
	testEnded();
	testStarted("test_for_pushing_int_element_in_stack");
	setup();
		test_for_pushing_int_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_for_pushing_float_element_in_stack");
	setup();
		test_for_pushing_float_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_for_pushing_char_element_in_stack");
	setup();
		test_for_pushing_char_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_for_pushing_double_element_in_stack");
	setup();
		test_for_pushing_double_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_for_pushing_String_element_in_stack");
	setup();
		test_for_pushing_String_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_for_poping_int_element_from_stack");
	setup();
		test_for_poping_int_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_for_poping_float_element_from_stack");
	setup();
		test_for_poping_float_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_for_poping_char_element_from_stack");
	setup();
		test_for_poping_char_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_for_poping_double_element_from_stack");
	setup();
		test_for_poping_double_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_for_poping_string_element_from_stack");
	setup();
		test_for_poping_string_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_gives_top_int_element_of_stack");
	setup();
		test_gives_top_int_element_of_stack();
	tearDown();
	testEnded();
	testStarted("test_gives_top_float_element_of_stack");
	setup();
		test_gives_top_float_element_of_stack();
	tearDown();
	testEnded();
	testStarted("test_gives_top_double_element_of_stack");
	setup();
		test_gives_top_double_element_of_stack();
	tearDown();
	testEnded();
	testStarted("test_gives_top_char_element_of_stack");
	setup();
		test_gives_top_char_element_of_stack();
	tearDown();
	testEnded();
	testStarted("test_gives_top_string_element_of_stack");
	setup();
		test_gives_top_string_element_of_stack();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
