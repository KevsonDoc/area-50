import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';
import { MicroserviceOptions, Transport } from '@nestjs/microservices';
import { networkInterfaces } from 'os';

async function bootstrap() {
  console.log("Hello World");
  
  const interfaces = networkInterfaces();
  const addresses = [];

  for (const k in interfaces) {
    for (const k2 in interfaces[k]) {
      const address = interfaces[k][k2];
      if (address.family === 'IPv4' && !address.internal) {
        addresses.push(address.address);
      }
    }
  }
  console.log("lasndk.ajsdkjahdskj \n\n\n");
  

  const app = await NestFactory.create(AppModule);
  console.log(addresses);

  const mqtt = await NestFactory.createMicroservice<MicroserviceOptions>(
    AppModule,
    {
      transport: Transport.MQTT,
      options: {
        url: `mqtt://${addresses[0]}:1883`,
      },
    },
  );

  await app.listen(3000);
  await mqtt.listen();
}

bootstrap();
