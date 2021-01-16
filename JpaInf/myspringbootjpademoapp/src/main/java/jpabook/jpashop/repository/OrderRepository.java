package jpabook.jpashop.repository;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.TypedQuery;
import javax.persistence.criteria.CriteriaBuilder;
import javax.persistence.criteria.CriteriaQuery;
import javax.persistence.criteria.Join;
import javax.persistence.criteria.JoinType;
import javax.persistence.criteria.Predicate;
import javax.persistence.criteria.Root;

import org.springframework.stereotype.Repository;
import org.springframework.util.StringUtils;

import jpabook.jpashop.domain.order.Order;
import jpabook.jpashop.repository.order.simplequery.SimpleOrderQueryDto;
import lombok.RequiredArgsConstructor;

@Repository
@RequiredArgsConstructor
public class OrderRepository {

	private final EntityManager em;

	public void save(Order order) {
		em.persist(order);
	}

	public Order findOne(Long id) {
		return em.find(Order.class, id);
	}

	public List<Order> findAllByString(OrderSearch orderSearch) {
		// language=JPAQL
		String jpql = "select o From Order o join o.member m";
		boolean isFirstCondition = true;
		// 주문 상태 검색
		if (orderSearch.getOrderStatus() != null) {
			if (isFirstCondition) {
				jpql += " where";
				isFirstCondition = false;
			} else {
				jpql += " and";
			}
			jpql += " o.status = :status";
		}
		// 회원 이름 검색
		if (StringUtils.hasText(orderSearch.getMemberName())) {
			if (isFirstCondition) {
				jpql += " where";
				isFirstCondition = false;
			} else {
				jpql += " and";
			}
			jpql += " m.username like :name";
		}
		TypedQuery<Order> query = em.createQuery(jpql, Order.class).setMaxResults(1000); // 최대 1000건
		if (orderSearch.getOrderStatus() != null) {
			query = query.setParameter("status", orderSearch.getOrderStatus());
		}
		if (StringUtils.hasText(orderSearch.getMemberName())) {
			query = query.setParameter("name", orderSearch.getMemberName());
		}
		return query.getResultList();
	}

	/**
	 * JPA Criteria
	 */
	public List<Order> findAllByCriteria(OrderSearch orderSearch) {
		CriteriaBuilder cb = em.getCriteriaBuilder();
		CriteriaQuery<Order> cq = cb.createQuery(Order.class);
		Root<Order> o = cq.from(Order.class);
		Join<Object, Object> m = o.join("member", JoinType.INNER);

		List<Predicate> criteria = new ArrayList<>();

		// 주문 상태 검색
		if (orderSearch.getOrderStatus() != null) {
			Predicate status = cb.equal(o.get("status"), orderSearch.getOrderStatus());
			criteria.add(status);
		}
		// 회원 이름 검색
		if (StringUtils.hasText(orderSearch.getMemberName())) {
			Predicate name = cb.like(m.get("name"), "%" + orderSearch.getMemberName() + "%");
			criteria.add(name);
		}

		cq.where(cb.and(criteria.toArray(new Predicate[criteria.size()])));
		TypedQuery<Order> query = em.createQuery(cq).setMaxResults(1000);

		return query.getResultList();
	}
	
	/**
	 * Fetch 조인으로 조회 성능 최적화
	 */
	public List<Order> findAllWithMemberDelivery() {
		List<Order> resultList = em.createQuery("select o from Order o" + 
						" join fetch o.member m" +
						" join fetch o.delivery d", Order.class)
					.getResultList();
		return resultList;
	}
	
	/**
	 * DTO 클래스를 JPQL 쿼리 시 사용하여 Join 쿼리를 짬.
	 * 쿼리가 간결해지지만 직접 SQL을 짜듯이 사용하는 것이기 때문에 재사용성이 떨어진다.
	 * 장점은 v3보다는 성능 최적화가 된다.
	 */
	public List<SimpleOrderQueryDto> findOrderDtos() {
		List<SimpleOrderQueryDto> resultList = em.createQuery("select new jpabook.jpashop.repository.order.simplequery.SimpleOrderQueryDto(o.id, m.username, o.orderDate, o.status, d.address)" + 
														" from Order o" + 
														" join o.member m" + 
														" join o.delivery d", SimpleOrderQueryDto.class)
													.getResultList();
		return resultList;
	}

	public List<Order> findAllWithItem() {
		List<Order> resultList = em.createQuery("select distinct o from Order o" + 
						" join fetch o.member m" +
						" join fetch o.delivery d" +
						" join fetch o.orderItems oi" +
						" join fetch oi.item i", Order.class)
				.getResultList();
		return resultList;
	}

	public List<Order> findAllWithMemberDelivery(int offset, int limit) {
		List<Order> resultList = em.createQuery("select o from Order o" + 
					" join fetch o.member m" +
					" join fetch o.delivery d", Order.class)
				.setFirstResult(offset)
				.setMaxResults(limit)
				.getResultList();
		return resultList;
	}
	
	/**
	 * JPA QueryDSL
	 */
//	public List<Order> findAllByQueryDSL(OrderSearch orderSearch) {
//
//	}

}
