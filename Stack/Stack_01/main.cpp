#include <iostream>
#include "Stack.h"

int main(int argc, char **argv)
{
    Stack<char> st(5);
    st.push('r');
    st.push('*');
    st.push('k');
    st.push('j');
    st.push('&');
    st.display();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.display();
	return 0;
}
