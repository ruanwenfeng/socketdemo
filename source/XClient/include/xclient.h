#ifndef XCLIENT_H
#define XCLIENT_H



#    ifdef TEST_EXPORTS
/* We are building this library */
#      define TEST_EXPORT __declspec(dllexport)
#    else
/* We are using this library */
#      define TEST_EXPORT /*__declspec(dllimport)*/
#    endif

class TEST_EXPORT TestLib {
public:
	 TestLib();
};

#endif // !XCLIENT_H
