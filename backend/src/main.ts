import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';
import { MicroserviceOptions, Transport } from '@nestjs/microservices';
import { MqttModule } from './mqtt/mqtt.module';

async function bootstrap() {
  const app = await NestFactory.create(AppModule);
  const mqtt = await NestFactory.createMicroservice<MicroserviceOptions>(
    MqttModule,
    {
      transport: Transport.MQTT,
      options: {
        url: process.env.MQTT_HOST,
        clientId: 'node-server',
        username: 'tardis',
        password: 'root',
      },
    },
  );

  await app.listen(3000);
  await mqtt.listen();
}

bootstrap();
