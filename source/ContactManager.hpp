/* Manages all Contact objects. Creates new Contact objects and deletes and/or grants access to existing Contact objects. */
class ContactManager {
private:
	//a vector that holds all Contact objects
	std::vector<Contact> contacts;
	
public:
	/* Returns the size of the 'contacts' vector, which represents the number of stored contacts. */
	size_t getSize() const;

	/* Adds a new Contact object that was created either in the Console class or GUI class to the 'contacts' vector. */
	void add(const Contact& contact);
	
	//overloaded method: removes an existing contact using a given element
	/* Removes an existing contact using the position of the Contact in the 'contacts' vector. */
	void remove(std::size_t element);
	/* Removes an existing contact using a reference to a Contact object. */
	void remove(const Contact& contact);
	/* Removes an existing contact using a reference to the contact's full name. */
	void remove(const std::string& fullName);
	
	//overloaded method: returns a pointer to a Contact object using a given element
	/* Returns a reference to a Contact object using the position of the Contact in the 'contacts' vector. Contact object may be modified. */
	Contact* const get(std::size_t element);
	/* Returns a pointer to a Contact object using the position of the Contact in the 'contacts' vector.  */
	const Contact* const get(std::size_t element) const;
	/* Returns a pointer to a Contact object using a reference to the contact's full name. May modify the reference to the object or the object itself. */
	Contact* const get(const std::string& fullName);
	/* Returns a reference to a Contact object using a reference to the contact's full name. May not be modified at all. */
	const Contact* const get(const std::string& fullName) const;

	/*
		fileformat
		
		[limiter] is a specified limiter, used for limiting all fields and all contacts
		Indentation and break lines are only used for documentation and therefore not used in the fileformat itself
		[limiter] is a nullbyte (ascii value is zero)
		
		[limiter]
			[limiter][FullName][limiter]
			[limiter][LastName][limiter]
			[limiter][Address][limiter]
			[limiter][Email][limiter]
			[limiter][Phone][limiter]
			[limiter][Notes][limiter]
		[limiter]
	*/	

	/* Writes all Contact objects in the 'contacts' vector into a specified file. */
	void save(const std::string& fileName) const;
	/* Retrieves all Contact objects in the 'contacts' vector from a specified file. */
	void load(const std::string& fileName);
};
