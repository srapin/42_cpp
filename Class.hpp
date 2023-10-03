class Example
{
	protected:

	public:
		Example();
        Example(const Example& other);
        virtual ~Example();
        Example &operator=(const Example& other);
		
};