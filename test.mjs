import { GoogleGenAI } from "@google/genai/node";

const ai = new GoogleGenAI({});

async function main() {
  const response = await ai.models.generateContent({
    model: "gemini-2.5-flash",
    contents: "Hello!",
  });
  console.log(response.text);
}

main();
