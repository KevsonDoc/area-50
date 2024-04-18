import { Injectable, Logger } from '@nestjs/common';
import { DHT11SensorDto } from './dto/dht11-sensor.dto';
import { PrismaClient } from '@prisma/client';

@Injectable()
export class MqttService {
  private prisma: PrismaClient;

  constructor() {
    this.prisma = new PrismaClient();
  }

  public async insert(createMqttDto: DHT11SensorDto): Promise<void> {
    try {
      await this.prisma.sensor.create({
        data: createMqttDto,
      });
    } catch (error) {
      Logger.error(error);
    }
  }
}
