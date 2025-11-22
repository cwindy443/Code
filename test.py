from google import genai
from google.genai import types

client = genai.Client()

response = client.models.generate_content(
    model = "gemini-3-pro-preview",
    contents = "Hello",
)

print(response.text)