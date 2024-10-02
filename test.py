import requests
from fpdf import FPDF

# URL of the chat
chat_link = "https://chatgpt.com/share/66ed06ad-d768-800b-8492-1e3eae67bb5b"

# Function to fetch chat data
def fetch_chat_data(url):
    # You need to handle authentication and response parsing here
    response = requests.get(url)
    if response.status_code == 200:
        return response.text  # Assuming the chat is returned as plain text
    else:
        return "Failed to fetch chat data"

# Function to create PDF from chat data
def create_pdf(chat_data, filename="chat.pdf"):
    pdf = FPDF()
    pdf.add_page()
    pdf.set_font("Arial", size=12)
    for line in chat_data.split('\n'):
        pdf.cell(200, 10, txt=line, ln=True)
    pdf.output(filename)

# Main execution
if __name__ == "__main__":
    chat_data = fetch_chat_data(chat_link)
    create_pdf(chat_data)
