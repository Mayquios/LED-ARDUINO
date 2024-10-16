import express from 'express';
import axios from 'axios';
import path from 'path';
const app = express();
const port = 3002;

app.use(express.static(path.join(process.cwd(), 'public')));



// Ruta para encender el LED
app.get('/led/on', async (req, res) => {
    try {
      await axios.get('http://192.168.1.6/led/on');
      res.send('LED encendido');
    } catch (error) {
        console.log(error)
      res.status(500).send('Error al encender el LED');
    }
  });
  
  // Ruta para apagar el LED
  app.get('/led/off', async (req, res) => {
    try {
      await axios.get('http://192.168.1.6/led/off');
      res.send('LED apagado');
    } catch (error) {
      res.status(500).send('Error al apagar el LED');
    }
  });
  
  app.listen(port, () => {
    console.log(`Servidor corriendo en http://localhost:${port}`);
  });