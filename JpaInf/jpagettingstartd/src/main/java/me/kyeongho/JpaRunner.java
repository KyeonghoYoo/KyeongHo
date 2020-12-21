package me.kyeongho;

import java.sql.Connection;

import javax.sql.DataSource;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.stereotype.Component;

@Component
public class JpaRunner implements ApplicationRunner {

	@Autowired
	DataSource dataSource;

	@Override
	public void run(ApplicationArguments args) throws Exception {
		try (Connection connection = dataSource.getConnection()) {
			System.out.println(connection.getMetaData().getURL());
			System.out.println(connection.getMetaData().getUserName());
		}
	}
}
