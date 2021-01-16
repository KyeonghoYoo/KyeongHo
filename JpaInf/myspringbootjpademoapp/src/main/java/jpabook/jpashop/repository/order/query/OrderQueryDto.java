package jpabook.jpashop.repository.order.query;

import java.time.LocalDateTime;
import java.util.List;

import jpabook.jpashop.domain.order.OrderStatus;
import jpabook.jpashop.domain.valtype.Address;
import lombok.Data;
import lombok.EqualsAndHashCode;

@Data
@EqualsAndHashCode(of = "orderId")
public class OrderQueryDto {

	private Long orderId;
	
	private String name;
	
	private LocalDateTime orderDate;
	
	private OrderStatus orderStatus;
	
	private Address address;
	
	private List<OrderItemQueryDto> orderItemQueryDtos;

	public OrderQueryDto(Long orderId, String name, LocalDateTime orderDate, OrderStatus orderStatus, Address address) {
		this.orderId = orderId;
		this.name = name;
		this.orderDate = orderDate;
		this.orderStatus = orderStatus;
		this.address = address;
	}
	
	public OrderQueryDto(Long orderId, String name, LocalDateTime orderDate, OrderStatus orderStatus, Address address,
			List<OrderItemQueryDto> orderItemQueryDtos) {
		this.orderId = orderId;
		this.name = name;
		this.orderDate = orderDate;
		this.orderStatus = orderStatus;
		this.address = address;
		this.orderItemQueryDtos = orderItemQueryDtos;
	}
	
	
}
