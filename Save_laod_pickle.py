# Function to save the state to a file
def save_state(controller, file_path):
    with open(file_path, 'wb') as file:
        pickle.dump(controller.integral, file)

# Function to load the state from a file
#Shoudn't be "__init__.integral"?
def load_state(controller, file_path):
    if os.path.exists(file_path):
        with open(file_path, 'rb') as file:
            controller.integral = pickle.load(file)